#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    int n, s[1010];
    while(cin >> n){
        if(n == 0)  break;
        double sum = 0, m = 0;
        for(int i = 1; i<=n; i++){
            cin >> s[i];
            m += s[i];
        }
        m = m/n;
        for(int i = 1; i<=n; i++){
            sum += (s[i] - m)*(s[i] - m);
        }
        cout << fixed;
        cout << setprecision(9) << sqrt(sum/n) << endl;
    }
    return 0;
}

