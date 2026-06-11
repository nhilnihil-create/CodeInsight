#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--, b--, c--, d--;
    string s;
    cin >> s;
    bool f1 = 1, f2 = 1;
    for(int i = a; i < c; i++){
        if (s[i] == '#' && s[i+1] == '#') f1 = 0;
    }
    for(int i = b; i < d; i++){
        if (s[i] == '#' && s[i+1] == '#') f2 = 0;
    }

    if (c < d){
        if (f1&&f2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        bool f3 = 0;
        for(int i = b; i <= d; i++){
            if (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') f3 = 1;
        }
        if (f1&&f2&&f3) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}
