#include <bits/stdc++.h>

using namespace std;
 
//#define int long long
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define reps(i,n) for(ll i=0;i<=n;i++)
#define PI 3.14159265358979323846264338327950L

ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
 
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ios_base::sync_with_stdio(false);
    ll h,n;
    cin >> h >> n;
    vector<ll> a(n,0);
    rep(i,n){
        cin >> a[i];
        h -= a[i];
        if(h<=0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
