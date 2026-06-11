#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    string s, t;
    cin >> s >> t;
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) res++;
    }
    cout << res << endl;
}