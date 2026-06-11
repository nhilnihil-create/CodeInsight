#include <bits/stdc++.h>
using namespace std; 
const int maxn = 5000500;
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    if(k == 1) return cout << 0 << '\n', 0;
    cout << n - k << '\n';
    return 0;

}