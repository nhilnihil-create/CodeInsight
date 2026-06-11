#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5 + 11;
int n;
LL num[N], a[71], nw[N];
void insert(LL x){
    for(int i = 60;i >= 0; i--){
        if((1LL << i & x) == 0)continue;
        if(a[i] != 0) x ^= a[i];
        else{
            for(int j = i - 1;j >= 0; j--){
                if(!a[j]) continue;
                if(1ll << j & x){
                    x ^= a[j];
                }
            }
            for(int j = i + 1;j <= 60; j++){
                if(1LL << i & a[j]){
                    a[j] ^= x;
                }
            }
            a[i] = x;
            return ;
        }
    }
}
int main(){
    cin>>n;
    LL ans = 0;
    for(int i = 1;i <= n; i++){
        scanf("%lld", &num[i]);
    }
    for(int i = 60;i >= 0; i--){
        int tot = 0;
        for(int j = 1;j <= n; j++){
            if(num[j] >> i & 1)tot++;
        }
        if((tot & 1) == 0){
            for(int j = 1;j <= n; j++){
                if(num[j] >> i & 1)nw[j] |= 1LL << i;
            }
        }
        else ans += 1LL << i;
    }
    for(int i = 1;i <= n; i++){
        insert(nw[i]);
    }
    //printf("ans=%lld\n", ans);
    LL x = 0;
    for(int i = 60;i >= 0; i--){
        if(a[i]){
            x ^= a[i];
            //printf("i=%d a=%lld\n", i, a[i]);
        }
    }
    ans += x * 2LL;
    cout<<ans<<endl;
    return 0;
}
