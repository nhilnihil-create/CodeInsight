#include <bits/stdc++.h>
using namespace std;

    int main() {
        
        long long int a;
        long double b;
        
        cin >> a >> b;
        int64_t ans = b*100+0.01;
        a*=ans;
        a/=100;
        cout << a;
        
    }