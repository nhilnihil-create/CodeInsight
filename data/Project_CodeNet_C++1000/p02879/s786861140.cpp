#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    int a,b; cin >> a >> b;
    int out =-1;
    if(0<a && a<10  && 0<b && b<10 ){
        out = a*b;
    }
    cout << out << endl;
    return 0;
}