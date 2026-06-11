#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    cout << fixed << setprecision(6);
    int n ; cin >> n;
    double out ;
    out = (double)(n/2+n%2)/n;
    cout << out << endl;
    return 0;
}