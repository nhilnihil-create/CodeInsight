#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
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
    int N;cin>>N;
    vector<ll> a(N);
    ll sum = 0,sum2 = 0;
    rep(i,N) {
        cin>>a[i];
        sum+=a[i];
        if(i%2==1) sum2+=2*a[i];
    }
    vector<ll> x(N);
    x[0] = sum - sum2;
    rep(i,N-1) {
        x[i+1] = 2 * a[i] - x[i];
    }
    rep(i,N) {
        cout<<x[i]<<" ";
        if(i==N-1) cout<<endl;
    }
}