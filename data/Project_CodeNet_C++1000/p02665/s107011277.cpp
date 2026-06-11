#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005];
ll p[100005];
ll S[100005];
ll ans=  0;
int main(){
    scanf("%d",&n);
    for (int i = 0; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    for (int i = n; i >= 0; i--){
        p[i] = p[i+1]+a[i];
    }
    for (int i = 0; i <= n; i++){
        S[i] = (i==0?1:2*S[i-1])-a[i];
        S[i] = min(S[i],p[i+1]);
        ans += S[i]+a[i];
        if (S[i] < 0){
            printf("-1\n");
            return 0;
        }
        //printf("%d %lld\n",i,S[i]);
    }
    printf("%lld",ans);

}
