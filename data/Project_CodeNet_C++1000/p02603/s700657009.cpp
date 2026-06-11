#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for (int i = (int)(n)-1; i>=0; --i)
#define For(i,a,b) for(auto i=(a);i<=(b);++i)
#define rFor(i,a,b) for(auto i=(b);i>=(a);--i)
#define call(var) cerr<<#var<<"="<<var<<"\n";
#define dup(x,y) (((x)+(y)-1)/(y))
#define all(x) (x).begin(),(x).end()
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const double pi = acos(-1);
template<class t,class u> inline bool chmax(t&a,u b){if(a<b){a=b;return true;}return false;}
template<class t,class u> inline bool chmin(t&a,u b){if(b<a){a=b;return true;}return false;}
template<class T> istream& operator>>(istream& is, vector<T>& a){rep(i,a.size()) is >> a[i]; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& a){rep(i,a.size()) os << a[i] << " "; return os;}
template<class T, class U> istream& operator>>(istream& is, pair<T,U>& p){is >> p.first >> p.second; return is;}
template<class T, class U> ostream& operator<<(ostream& os, const pair<T,U>& p){os << "("<< p.first << "," << p.second << ")"; return os;}
template<class T, class U> ostream& operator<<(ostream& os, const map<T,U>& mp){for(auto& t : mp) os << t.first << " " << t.second << "\n"; return os;}

int main(){
    int n;cin >> n;
    vl a(n);
    cin >> a;

    // i日目に株をj株持っているときのお金
    vl dp(n+1);
    dp[0] = 1000;
    for(int i=0;i<n;++i){
        // dp[i+1] の更新
        for(int j=0;j<=i;++j){
            dp[i+1] = max({dp[i+1], dp[j]/a[j] * a[i] + dp[j]%a[j], dp[j]});
        }
    }
    cout << dp[n] << endl;
}