#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
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
    int n;
    string s;
    cin >> n >> s;
    ll res = 0;
    repp(i,1000,2000){
        string str = to_string(i).substr(1);
        int ind = 0;
        bool b = false;
        rep(j,s.length()){
            if(str[ind] == s[j])ind++;
            if(ind == 3){
                b = true;
                break;
            }
        }
        if(b)res++;
    }
    cout << res << endl;
    return 0;
}