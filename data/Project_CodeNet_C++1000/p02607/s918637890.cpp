#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MOD = 1000000007;


int main(){
    int N; cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    int ans = 0;
    rep(i,N){
        if((i+1)%2 == 1 && a[i]%2 == 1) ans++;
    }
    cout << ans << endl;
}
