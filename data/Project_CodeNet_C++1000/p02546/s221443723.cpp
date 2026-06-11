#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define ull unsigned long long
#define ld long double
#define uint unsigned int
struct debug {
~debug() {cerr << "\n";}template<class C> debug& operator<<(C c) {cerr << c;return *this;}
};
#define var(x) " [" << #x << ": " << x << "]"

string s;

void solve() {
    cin >> s;
    if(s[s.length()-1]!='s') {
        cout << s << "s\n";
        return;
    }
    cout << s << "es\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}