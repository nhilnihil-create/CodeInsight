#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if (a>b) swap(a, b);
    ll ans = 0;
    if ((b-a)%2==0) {
        ans = (b-a)/2;
    }
    else {
        ans = a + (b-a-1)/2;
        chmin(ans, n-b+1+(b-a-1)/2);
    }
    
    
    cout << ans << endl;
    return 0;
}
