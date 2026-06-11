#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    ll h;
    cin >> h;
    ll now = 1;
    ll ans = 0;
    while(h){
        h/=2;
        now *= 2;
        ans += now/2;
    }
    cout << ans << endl;

    return 0;
}