// g++ -std=c++17 -O2 -Wall C.cpp -o C -D _DEBUG

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i++) ans += (n - 1) / i;
    cout << ans;
}