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
//  l int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int num[200010];

int cnt[2019];

int main() {
    string s;cin>>s;
    reverse(s.begin(),s.end());
    int pre = 0;
    int ten = 1;
    cnt[0]++;
    rep(i,s.size()) {
        num[i] = (pre + (s[i]-'0')*ten)%2019;
        cnt[num[i]]++;
        pre = num[i];   
        ten = ten*10%2019;
    }
    ll ans = 0;
    rep(i,2019) {
        // if(cnt[i]!=0) cout<<i<<" "<<cnt[i]<<endl;
        ans += cnt[i]*(cnt[i]-1)/2;
    }
    cout<<ans<<endl;
}