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
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int n,q;
vector<int> tree[200005];
int cnt[200005];
ll sum[200005];
int seen[200005];

void dfs(int n) {
    for(int i = 0;i<int(tree[n].size());i++) {
        if(!seen[tree[n][i]]) {
            seen[tree[n][i]] = 1;
            sum[tree[n][i]] = cnt[tree[n][i]] + sum[n];
            dfs(tree[n][i]);
        }
    }
}

int main() {
    cin>>n>>q;
    rep(i,n-1) {
        int a,b;cin>>a>>b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    } 
    rep(i,q) {
        int p,x;cin>>p>>x;
        cnt[p-1]+=x;
    }
    seen[0]=1;
    sum[0]=cnt[0];
    dfs(0);
    rep(i,n) {
        cout<<sum[i]<<" ";
        if(i==n-1) cout<<endl;
    }
}