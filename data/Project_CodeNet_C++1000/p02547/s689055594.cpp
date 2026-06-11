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

int n, a[100][2];

void solve() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
    for(int i=0; i+2<n; ++i) {
        if(a[i][0]==a[i][1]&&a[i+1][0]==a[i+1][1]&&a[i+2][0]==a[i+2][1]) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}