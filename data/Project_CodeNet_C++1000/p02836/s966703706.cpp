#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    string s; cin >> s;
    string t = s;
    reverse(ALL(t));

    int ans = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] != t[i]) ans++;
    }
    cout << ans / 2 << endl;

    return 0;
}
