#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    long int n, a, b;
    cin >> n >> a >> b;
    
    long int ans = n / (a+b) * a;
    
    n %= a + b;
    if(n < a)
        cout << ans + n << endl;
    else
        cout << ans + a << endl;
    
    return 0;
}


