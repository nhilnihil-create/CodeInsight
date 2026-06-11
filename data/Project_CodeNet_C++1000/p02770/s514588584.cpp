#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int k,q;
    scanf("%d%d",&k,&q);
    int d[k];
    for (int i = 0; i < k; i++){
        scanf("%d",&d[i]);
    }
    while (q--){
        int n,x,m;
        scanf("%d%d%d",&n,&x,&m);
        ll ans = 0;
        n--;
        ll total = x%m;
        for (int i = 0; i < k; i++){
            int T = (n/k) + (n%k > i);
            total += (ll)T*(d[i]%m);
            if (d[i]%m) ans+=T;
        }
        ans -= total/m;
        printf("%d\n",ans);
    }
}
