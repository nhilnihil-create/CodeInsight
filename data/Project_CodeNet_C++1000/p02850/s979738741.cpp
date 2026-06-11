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

int a[100010],b[100010];
vector<int> ki[100010];
int par_col[100010];
bool seen[100010];

int main () {
    int n;cin>>n;
    int mx=0;
    rep(i,n-1) {
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        ki[a[i]].push_back(b[i]);
        ki[b[i]].push_back(a[i]);
        mx=max(mx,(int)ki[a[i]].size());
        mx=max(mx,(int)ki[b[i]].size());
    }
    map<P,int> ma;
    queue<int> qu;
    qu.push(0);
    seen[0]=true;
    par_col[0]=-1;
    while(!qu.empty()){
        int now = qu.front();qu.pop();
        int col = 0;
        for(auto nxt: ki[now]) {
            if(!seen[nxt]) {
                seen[nxt]=true;
                if(col == par_col[now]) col = (col+1)%mx;
                par_col[nxt]=col;
                ma[P(now,nxt)]=col;
                ma[P(nxt,now)]=col;
                col++;
                qu.push(nxt);
            }
        }
    }
    cout<<mx<<endl;
    rep(i,n-1) {
        cout<<ma[P(a[i],b[i])]+1<<endl;
    }
}