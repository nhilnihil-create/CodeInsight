#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
 
int main(){
    double n, x, y;cin >> n;
    vector<double> xi;
    vector<double> yi;
    double D = 0.0;
    for(int i = 0; i < n; i++){
        cin >> x;
        xi.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> y;
        yi.push_back(y);
    }
    //p=1
    for(int i = 0; i < n; i++){
    D = abs(xi[i] - yi[i]) + D;
    }
    cout << fixed << D << endl;
    //p=2
    D=0.0;
    for(int i = 0; i < n; i++){
    D = pow(abs(xi[i] - yi[i]), 2.0) + D;
    }
    cout << fixed << sqrt(D) << endl;
    //p=3
    D = 0.0;
    for(int i = 0; i < n; i++){
    D = pow(abs(xi[i] - yi[i]), 3.0) + D;
    }
    cout << fixed << pow(D, 1.0 / 3.0) << endl;
    //p=mugen
    D = 0.0;
    for(int i = 0; i < n; i++){
        D = max(D, abs(xi[i] - yi[i]));
    }
    cout << fixed << D << endl;
    return 0;
}
        
        