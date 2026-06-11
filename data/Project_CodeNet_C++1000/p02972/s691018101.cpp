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

int a[200010];
int ans[200010];

int main() {
    int n;cin>>n;
    rep(i,n) cin>>a[i+1];
    int m=0;
    for (int i = n;i>=1;i--) {
        int sum = 0;
        int tim = 2;
        while(i*tim<=n) {
            sum+=ans[i*tim];
            tim++;
        }
        if(sum%2 == a[i]%2) {
            ans[i]=0;
        } else {
            ans[i]=1;
            m++;
        }
    }
    cout<<m<<endl;
    rep(i,n) {
        if(ans[i+1]) cout<<i+1<<" ";
        if(i==n-1) cout<<endl;
    }
}