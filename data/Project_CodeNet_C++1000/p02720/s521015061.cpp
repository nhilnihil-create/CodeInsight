#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
    int k;cin>>k;
    // if(k<=9) {
    //     cout<<k<<endl;
    //     return;
    // }
    int cnt=0;
    queue<ll> que;
    rep(i,9) que.push(i+1);
    while(1) {
        ll now = que.front();que.pop();
        cnt++;
        if(cnt==k) {
            cout<<now<<endl;
            return 0;
        }
        if(now%10==0) {
            que.push(now*10);
            que.push(now*10+1);
        } else if (now%10==9) {
            que.push(now*10+(now%10-1));
            que.push(now*10+(now%10));
        } else{
            que.push(now*10+(now%10-1));
            que.push(now*10+(now%10));
            que.push(now*10+(now%10+1));
        }
    }
}