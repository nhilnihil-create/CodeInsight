#include <bits/stdc++.h>
using namespace std;

#define ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
        
    int n, m;
    cin >> n >> m;
    m = (m * (m - 1)) / 2; 
    n = (n * (n - 1)) / 2;
    cout <<m + n<< endl;

    return 0;
}
