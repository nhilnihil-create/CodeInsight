#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 998244353;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
    int N,S;cin>>N>>S;
    vector<int> pre_v(S+10,0);
    pre_v[0] = 1;
    rep(i,N) {
        int A;cin>>A;
        vector<int> new_v(S+10,0);
        rep(j,S+1) {
            new_v[j] = 2 * pre_v[j] % MOD;
            if(j - A>=0) new_v[j] = (new_v[j] + pre_v[j-A]) %MOD;
        }
        pre_v = new_v; 
    }
    cout<<pre_v[S]<<endl;
}