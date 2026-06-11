#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << max((c - max(abs(a-b), 0LL)), 0LL) << "\n";
    return 0; 
}