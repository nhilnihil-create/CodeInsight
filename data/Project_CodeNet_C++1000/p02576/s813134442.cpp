#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);	
    
    int x, y, t;
    cin >> x >> y >> t;
    t *= ceil((double) x/y);
    cout << t;
    
    return 0;
} 
 
