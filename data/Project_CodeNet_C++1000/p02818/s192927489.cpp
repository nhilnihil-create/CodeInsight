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
    long long a,b,k ; cin >> a >> b >> k;
    long long n=a,m=b;
    if(a>k) n = a-k;
    else if(b > k-a) {
        n= 0;
        m = b-(k-a);
    }else{
        n=0;m=0;
    }
    cout << n << " " <<m << endl;
    return 0;
}