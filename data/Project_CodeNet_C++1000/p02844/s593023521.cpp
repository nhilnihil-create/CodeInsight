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
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(char i='0';i<='9';i++){
        ll p = s.find(i);
        if(p == string::npos)continue;
        for(char j='0';j<='9';j++){
            ll q = s.find(j, p+1);
            if(q == string::npos)continue;
            for(char k='0';k<='9';k++){
                ll r = s.find(k,q+1);
                if(r == string::npos)continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
}