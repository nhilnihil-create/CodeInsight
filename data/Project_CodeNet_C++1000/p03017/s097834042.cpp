#include <bits/stdc++.h>
#define repl(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    if(c < d){
        repl(i,a,max(c,d))if(s[i] == s[i+1] && s[i] == '#'){
            cout << "No\n";
            return 0;
        }
        cout << "Yes\n";
    }else{
        repl(i,a,max(c,d))if(s[i] == s[i+1] && s[i] == '#'){
            cout << "No\n";
            return 0;
        }
        repl(i,b-1,d)if(s[i-1] == s[i] && s[i] == s[i+1] && s[i] == '.'){
            cout << "Yes\n";
            return 0;
        }
        cout << "No\n";
    }
    return 0;
}