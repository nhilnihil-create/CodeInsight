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
    ll h,n,ma=0;
    cin >> h >> n;
    vector<ll> A(n,0);
    vector<ll> B(n,0);
    vector<ll> DP(h+1,INF);

    rep(i,n){
        cin >> A[i] >> B[i];
    }

    DP[0] = 0;

    for(int i=0;i<=h;i++){
        for(int j=0;j<n;j++){
            chmin(DP[min(i+A[j],h)],DP[i]+B[j]);
        }
    }

    cout << DP[h] << endl;

    return 0;
}
