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

int n;

void solve() {
    cin >> n;
    int a=n^1;
    cout << a << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}