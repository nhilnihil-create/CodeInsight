#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<int> vint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;

lint powint(lint x, lint y){
    int ret = 1;
    for (int i=0; i < y; i++) ret *= x;
    return ret;
};

lint mod = 1000000007;
vector<int> dx = {1, 0, 0, -1, 1, 1, -1, -1};
vector<int> dy = {0, -1, 1, 0, 1, -1, 1, -1};

map<char, long long> counter(string s){
    map<char, long long> count;
    rep(i, s.size()){
        count[s[i]] ++;
    }
    return count;
};

int powmod(int x, int y, int m){
    if (y == 0) return 1;
    return ((powint(powmod(x, y>>1, m), 2) % m) * powint(x, (y & 1))) % m;
};

int main() {
    lint n, p; cin >> n >> p;
    string s; cin >> s;

    map<int, lint> cnt;
    lint ans = 0;
    if (p == 2){
        rep(i, n){
            if ((int)(s[i] - '0') % 2 == 0) ans += i + 1;
        }
    }
    else if (p == 5){
        rep(i, n){
            if (s[i] == '0' || s[i] == '5') ans += i + 1;
        }
    }
    else{
        int check = 1;
        int a = 0;
        cnt[0] ++;
        For(i, 1, n+1){
            a = (a + (int)(s[n-i] - '0') * powmod(10, i-1, p)) % p;
            cnt[a] ++;
        }
        for (auto i = cnt.begin(); i != cnt.end(); ++i){
            ans += (i -> second) * ((i -> second)-1)/2;
        }
        
    }
    cout << ans << endl;
}

