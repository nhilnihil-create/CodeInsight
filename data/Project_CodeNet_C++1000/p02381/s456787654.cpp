#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    int s[1000] = {};
    double m, a;
    
    while(true) {
        m = 0;
        a = 0;
        cin >> n;
        
        if(n == 0)   break;
        
        for(int i = 0; i < n; ++i) {
            cin >> s[i];
            m += s[i];
        }
        m /= n;
        
        for(int i = 0; i < n; ++i) {
            a += (s[i] - m)*(s[i] - m);
        }
        a = sqrt(a / n);
        
        printf("%lf\n", a);
    }
    
    return 0;
}
