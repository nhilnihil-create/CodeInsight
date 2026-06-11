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

int main() {
    int n,x,y;cin>>n>>x>>y;
    vector<int> tree[2005];
    int seen[2005];
    rep(i,n) {
        tree[i].push_back(i+1);
        tree[i+1].push_back(i);
    }
    tree[x-1].push_back(y-1);
    tree[y-1].push_back(x-1);
    int dist[2005][2005];
    for(int i=0;i<n;i++) {
        rep(j,n) seen[j]=0;
        queue<int> que;
        que.emplace(i);
        seen[i]=1;
        while(!que.empty()) {
            int now = que.front();
            que.pop();
            for(int j = 0;j<int(tree[now].size());j++) {
                int nxt = tree[now][j];
                if(!seen[nxt]) {
                    seen[nxt]=1;
                    dist[i][nxt] = dist[i][now]+1;
                    que.emplace(nxt);
                }
            }
        }
    }
    int ans[2005];
    rep(i,n) {
        rep(j,n) {
            ans[dist[i][j]]++;
        }
    }
    rep(i,n) {
        if(i!=0) cout<< ans[i]/2 <<endl;
    }
}