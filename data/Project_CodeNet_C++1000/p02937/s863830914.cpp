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
    string S,T;cin>>S>>T;
    int N = S.size(),M = T.size();
    vector<vector<int>> plc(26,vector<int>());
    rep(i,N) plc[S[i]-'a'].push_back(i);
    int now = 0;
    ll cnt = 0;

    rep(i,M) {
        int num = T[i] - 'a';
        if(plc[num].size()==0) {
            cout<<-1<<endl;
            return 0;
        }
        int loc = lower_bound(plc[num].begin(),plc[num].end(),now) - plc[num].begin();
        if(loc == plc[num].size()) {
            now = plc[num][0]+1;
            cnt++;
        } else {
            now = plc[num][loc]+1;
        }
    }
    cout<<cnt*N+now<<endl;
}