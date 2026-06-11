#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int m;
    scanf("%d",&m);
    ll ans = 0;
    ll sum = 0;
    ll dsum = 0;
    for (int i = 0; i < m; i++){
        int d;
        ll c;
        scanf("%d%lld",&d,&c);
        sum += c;
        dsum += d*c;
    }
    ans = (dsum-1)/9 + sum - 1;
    printf("%lld",ans);
}
