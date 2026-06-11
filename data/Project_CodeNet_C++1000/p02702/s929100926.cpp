#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(),s.end());
    vector<int>cnt(2019);
    int now = 0;
    ll ans = 0;
    int digit = 1;
    cnt[0]++;
    rep(i, 0, n){
        now = (now+(s[i]-'0')*digit)%2019;
        ans += cnt[now];
        cnt[now]++;
        digit = (digit*10) % 2019;
    }
    cout << ans << endl;
}