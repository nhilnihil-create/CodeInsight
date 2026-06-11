#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    // Here your code !
    int n;
    int s[1000];
    double m, a;
    cin >> n;
    do {
        for(int i=0;i<n;i++) {
            cin >> s[i];
        }
        m = 0;
        for(int i=0;i<n;i++) {
            m = m + s[i];
        }
        m = m / n;
        a = 0;
        for(int i=0;i<n;i++) {
            a = a + pow(s[i] - m, 2);
        }
        a = sqrt(a / n);
        cout << fixed
             << setprecision(5)
             << a << endl;
        cin >> n;
    } while(n != 0);
    
}