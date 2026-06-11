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
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] + n <= 'Z') cout << char(s[i] + n);
        else cout << char('A' + n - ('Z' - s[i]) - 1);
    }
    cout << "\n";

    return 0;
}
