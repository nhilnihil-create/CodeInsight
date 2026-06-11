#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, l, r;
    cin >> n >> m;
    
    l = 1, r = m;
    while(l < r) {
        cout << l << " " << r << '\n';
        ++l, --r;
    }

    l = m+1, r = 2*m+1;
    while(l < r) {
        cout << l << " " << r << '\n';
        ++l, --r;
    }
}