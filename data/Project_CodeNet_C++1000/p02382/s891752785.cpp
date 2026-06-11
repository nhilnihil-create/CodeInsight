#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    long n, x[110], y[110], sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < n; i++){
        cin >> y[i];
    }
    for(int i = 0; i < n; i++){
        sum1 += pow(abs(x[i]-y[i]), 1);
        sum2 += pow(abs(x[i]-y[i]), 2);
        sum3 += pow(abs(x[i]-y[i]), 3);
        sum4 =  max(sum4, abs(x[i]-y[i]));
    }
    cout <<fixed;
    cout << setprecision(7) << pow(sum1, 1) << endl;
    cout << setprecision(7) << pow(sum2, 1.0/2) << endl;
    cout << setprecision(7) << pow(sum3, 1.0/3) << endl;
    cout << setprecision(7) << double (sum4) << endl;
    
    return 0;
}

