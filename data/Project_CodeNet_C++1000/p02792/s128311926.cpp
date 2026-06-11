#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;

P freq(int x){
    int a = x%10;
    int b;
    while(x){
        b = x;
        x /= 10;
    }
    return P(a,b);
}

int main(){
    int n;
    cin >> n;
    map<P,int> fr;

    for(int i=1; i<=n; i++){
        P p = freq(i);
        fr[p]++;
    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        P p = freq(i);
        P q(p.second,p.first);
        ans += fr[q];
    }
    cout << ans << endl;
    return 0;
}