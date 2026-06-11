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
    int N,K;cin>>N>>K;
    string S;cin>>S;
    char initial = S[0];
    int cnt = 0, ans = 0,last = 0;
    char find;
    if(S[0] == 'L') find = 'R';
    else find = 'L';
    rep(i,N-1) {
        if(S[i+1]==find) {
            if(find == initial) cnt++;
            if(cnt>=K) {
                last = i+1;
                // cout<<last<<endl;
                break;
            }
            if(find == 'L') find = 'R';
            else find = 'L';
        }
        if(i==N-2&&find==initial) {
            last = N-1;
            // cout<<last<<endl;
        }
        if(i==N-2&&cnt<K) {
            // cout<<cnt<<endl;
            last = N-1;
        }
    }
    // cout<<last<<endl;
    ans += last;
    char now = S[last];
    for(int j = last+1;j<N;j++) {
        if(S[j] == now) {
            ans++;
        }
        now = S[j];
    }
    cout<<ans<<endl;
}