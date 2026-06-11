#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#define MAX_N 100
using namespace std;

int main(void){
    int n;
    int x[MAX_N];
    int y[MAX_N];
    int i;
    
    int dif, sum_dif, sq_sum_dif, max_dif;
    long int cb_sum_dif;
    sum_dif = sq_sum_dif = cb_sum_dif = max_dif = 0;
    
    cin >> n;
    for(i = 0; i < n; i++) cin >> x[i];
    for(i = 0; i < n; i++){
        cin >> y[i];
        
        dif = abs(x[i] - y[i]);
        sum_dif += dif;
        sq_sum_dif += dif*dif;
        cb_sum_dif += dif*dif*dif;
        if(max_dif < dif) max_dif = dif;
    }
    
    cout << fixed << sum_dif << endl << sqrt(sq_sum_dif) << endl << cbrt(cb_sum_dif) << endl<< max_dif;
    return 0;
}