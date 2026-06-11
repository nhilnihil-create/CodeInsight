#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> Pair;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll INFL = 1e18;


int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    ans = n*(n-1)/2;
    cout << ans << endl;
    return 0;
}