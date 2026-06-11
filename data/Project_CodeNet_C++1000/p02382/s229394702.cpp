#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
#include <array>

using namespace std;

int main(void) {
    int n;
    int i;
    double sum;
    vector<int> x, y;
    
    //Read input
    cin >> n;
    
    for(i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    
    for(i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        y.push_back(tmp);
    }
    
//    //Test display
//    for(int i=0; i<n; i++) {
//        cout << x[i] << " ";
//    }
//    cout << endl;
//    for(i=0; i<n; i++) {
//        cout << y[i] << " ";
//    }
//    cout << endl;
    
    //Calc. p=1
    sum = 0;
    for(i=0; i<n; i++) {
        sum += abs(x[i]-y[i]);
    }
    cout << fixed << setprecision(6) << sum << endl;
    
    //Calc. p=2
    sum = 0;
    for(i=0; i<n; i++) {
        sum += pow( x[i]-y[i], 2);
    }
    sum = sqrt(sum);
    cout << fixed << setprecision(6) << sum << endl;
    
    //Calc. p=3
    sum = 0;
    for(i=0; i<n; i++) {
        sum += pow(abs(x[i]-y[i]), 3);
    }
    sum = pow( sum, 1.0/3.0);
    cout << fixed << setprecision(6) << sum << endl;
    
    //Calc. p=INF
    sum = 0;
    for(i=0; i<n; i++) {
        double tmp = abs(x[i]-y[i]);
        if(sum < tmp)
            sum = tmp;
    }
    cout << fixed << setprecision(6) << sum << endl;
    
    
    
    
    
    return 0;
}