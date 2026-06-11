#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int a[100005], cnt[100005], tmp[100005];
int main(){
    int n, ans = 1;
    scanf("%d", &n);
    bool ok = 1;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        tmp[a[i]]++;
        if(tmp[a[i]] > 3) ok = 0;
        if(a[i] > 0){
            ans = ans*1ll*cnt[a[i]-1]%mod;
            cnt[a[i]-1]--;
        }
    }
    if(!ok) printf("0\n");
    else{
        if(tmp[0] == 1) ans = ans*1ll*3%mod;
        else ans = ans*1ll*6%mod;
        printf("%d\n", ans);
    }
}