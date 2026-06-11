#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    long int h;
    cin >> h;
    
    long int n = 1;
    long int sum = 0;
    while(h > 1) {
        sum += n;
        
        h /= 2;
        n *= 2;
    }
    
    cout << sum + n << endl;
    
    
    return 0;
}


