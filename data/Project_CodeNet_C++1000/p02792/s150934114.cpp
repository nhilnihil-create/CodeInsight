#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    map<pair<char, char>, ll> M;
    for(int i = 1; i <= N; i++) {
        string s = to_string(i);
        char head = s[0], tail = s.back();
       pair<char,char> p(head, tail);
        if(!M.count(p)) M[p] = 1;
        else M[p]++;
    }
    ll ans = 0;
    for(auto u: M) {
        char H = u.first.first, T = u.first.second;
        ll num = u.second;
        pair<char, char> test(T, H);
        if(M.count(test)) ans += num * M[test];
    }
    cout << ans << endl;
    return 0;
}