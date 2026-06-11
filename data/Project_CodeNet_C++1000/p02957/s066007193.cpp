#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ar array
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int a, b;
    cin >> a >> b;
    if ((a + b) & 1) cout << "IMPOSSIBLE\n";
    else cout << (a + b) / 2 << '\n';
}