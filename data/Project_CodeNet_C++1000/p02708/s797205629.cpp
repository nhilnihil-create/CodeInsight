#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

const long int D = 1000000007;

int main() {
    long int n, k;
    cin >> n >> k;
    
    long int cnt = 0;
    for(long int i = k; i <= n+1; i++) {
        
        cnt += ((n-i+1) * i + 1) % D;
        cnt %= D;
    }
    
    cout << cnt << endl;
    
    return 0;
}
