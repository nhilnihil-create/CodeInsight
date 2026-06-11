#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){
    return x * x;
}

int main(void){
    double s[1001], n, m, sum, ans;
    while(1){
        cin >> n;
        if(n == 0)  break;
        sum = 0;
        for(int i = 0; i < n; i++){
            cin >> s[i];
            sum += s[i];
        }
        m = sum / n;
        ans = 0;
        for(int i = 0; i < n; i++){
            ans += f(s[i] - m);
        }
        cout << fixed << setprecision(8) << sqrt(ans / n) << endl;

    }
    
    return 0;
}

