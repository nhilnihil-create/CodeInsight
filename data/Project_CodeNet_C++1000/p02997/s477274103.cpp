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
    int N,K;cin>>N>>K;
    int mx = (N-1)*(N-2)/2;
    if(mx < K) {
        cout<<-1<<endl;
        return 0;
    }
    int num = mx - K;
    vector<vector<int>> g(N,vector<int>());
    num+=N-1;

    rep(i,N-1) {
        for(int j = i+1;j<N;j++) {
            if(num > 0) {
                g[i].push_back(j);
                num--;
            } else {
                cout<<mx-K+N-1<<endl;
                rep(i,N) {
                    if(g[i].size()!=0) {
                        for(auto to : g[i]) {
                            cout<<i+1<<" "<<to+1<<endl;
                        }
                    }
                }
                return 0;
            }
        }
    }
    cout<<mx-K+N-1<<endl;
    rep(i,N) {
        if(g[i].size()!=0) {
            for(auto to : g[i]) {
                cout<<i+1<<" "<<to+1<<endl;
            }
        }
    }

}