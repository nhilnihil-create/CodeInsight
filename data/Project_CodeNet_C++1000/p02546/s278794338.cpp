#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;

int main() {
    string s;
    cin >> s;
    if (s.back() == 's')
        cout << s << "es" << endl;
    else cout << s << "s" << endl;
}