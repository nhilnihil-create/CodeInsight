#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;

int main() {
    ll n,a,b,c,d; cin >> n >> a >> b >> c >> d;
    string s; cin >> s;
    s = '#' + s + '#';
    n = s.size();
    bool flag = false;

    if(c < d){
        flag = true;
    }else {
        for (int i = b; i <= d; ++i) {
            if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
                flag = true;
            }
        }
    }
    for (ll i = a; i <= max(c,d); ++i) {
        if (s[i - 1] == '#' && s[i] == '#') {
            flag = false;
        }
    }
    if(flag)print("Yes");
    else print("No");
}