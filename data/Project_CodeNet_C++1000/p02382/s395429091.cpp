#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){
    return x * x;
}

int main(void){
    double x[101], y[101], n, ans;
    cout << fixed << setprecision(6);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < n; i++){
        cin >> y[i];
    }
    
    ans = 0;
    // p = 1
    for(int i = 0; i < n; i++){
        ans += fabs(x[i] - y[i]);
    }
    cout << ans << endl;
    
    //p = 2
    ans = 0;
    for(int i = 0; i < n; i++){
        ans += f(fabs(x[i] - y[i]));
    }
    cout << sqrt(ans) << endl;
    
    //p = 3
    ans = 0;
    for(int i = 0; i < n; i++){
        ans += pow((fabs(x[i] - y[i])), 3.0);
    }
    cout << pow(ans, 1.0 / 3.0) << endl;
    
    
    //p = inf
    ans = 0;
    for(int i = 0; i < n; i++){
        if(ans <= fabs(x[i] - y[i]))
            ans = fabs(x[i] - y[i]);    
    }
    cout << ans << endl;

    return 0;
}

