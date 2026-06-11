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
    int out =0;
    if(a > b*2){
        out = a - b*2;
    }
    cout << out << endl;
    return 0;
}