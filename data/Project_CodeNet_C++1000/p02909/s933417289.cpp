#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    string s; cin >> s;
    if (s[0] == 'S') cout << "Cloudy" << endl;
    if (s[0] == 'C') cout << "Rainy" << endl;
    if (s[0] == 'R') cout << "Sunny" << endl;
    return 0;
}
