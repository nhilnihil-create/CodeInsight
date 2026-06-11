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

int main(){
    int N;cin>>N;
    vector<queue<int>> tbl(N);
    rep(i,N) {
        rep(j,N-1) {
            int a;cin>>a;
            a--;
            tbl[i].push(a);
        }
    }
    rep(i,N*(N-1)/2) {
        bool finished = true;
        vector<bool> seen(N,false);
        int cnt = 0;
        rep(j,N) {
            if(!tbl[j].empty()&&!seen[j]) {
                finished = false;
                seen[j] = true;
                int fst = tbl[j].front();
                int snd = tbl[fst].front();
                if(!seen[fst]&&snd == j) {
                    seen[fst] = true;
                    tbl[j].pop();
                    tbl[fst].pop();
                    cnt++;
                }
            }
        }
        if(finished) {
            cout<<i<<endl;
            return 0;
        } 
        if(cnt==0) {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<N*(N-1)/2<<endl;
}