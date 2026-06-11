#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;


int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    //scanf("%d", &tc);
    while(tc--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if((c - a - b) * (c - a - b) > 4 * a * b && c - a - b > 0) puts("Yes");
        else puts("No");
    }    
    return 0;
}