#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<double> A(n);
    double tot = 0;
    rep(i, n) {
        cin >> A[i];
        tot += A[i];
    }
    vector<double> B(n);
    double tot2 = 0;
    rep(i, n) {
        B[i] = tot / A[i];
        tot2 += B[i];
    }
    double ans;
    ans = tot / tot2;
    cout << fixed << setprecision(10) << ans << endl;
    
    return 0;
}