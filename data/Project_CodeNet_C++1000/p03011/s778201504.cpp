#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int p, q, r; cin >> p >> q >> r;
    cout << min(p + q, min(q + r, r + p));    
}