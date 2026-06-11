#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    long int n, s[1001], i;
    double m, a2, a;
    cin >> n;
    
    while(n != 0){
        m = 0;
        a2 = 0;
        for(i=0; i<n; i++){
            cin >> s[i];
            m += s[i];
        }
        m = m/n;
        for(i=0; i<n; i++){
            a2 += (s[i] - m) * (s[i] - m);
        }
        a2 = a2/n;
        a = sqrt(a2);
        
        cout << fixed << setprecision(5) << a << endl;
        
        cin >> n;
    }
    return 0;
}

