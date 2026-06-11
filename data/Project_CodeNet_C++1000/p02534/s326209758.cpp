#include <bits/stdc++.h>
 
using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define VVI vector<vector<int>>
#define PII pair<int,int>
#define VPII vector<PII>
#define LD long double
#define INF 1000000000000
#define MOD 1000000007
#define MAXR 100000 // array max range
#define FI first
#define SE second
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int K;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(6);
    cin >> K;
    R(i,K) cout << (i==K-1 ? "ACL\n" : "ACL");
    return 0;
}
