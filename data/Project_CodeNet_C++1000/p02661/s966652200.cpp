#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;
using vv = vector<vector<ll>>;
template <class _t> inline bool chmax (_t& a,_t b){if(a<b){a=b;return true;}return false;} template <class _t> inline bool chmin (_t& a,_t b){if(a>b){a=b;return true;}return false;}

const int INF = 2147483647;
const long long inf = 1ll << 60;
const long long mod = 1000000007;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int main(){
    int n;cin >>n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i] ;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans;
    if(n%2==0){
	ans = (b[n/2-1]+b[n/2])-(a[n/2-1]+a[n/2])+1;
    }else{
	ans = (b[n/2]-a[n/2])+1;	
    }
    cout << ans << endl;
    return 0;
}
