#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <stdio.h>
#include <set>
#include <iomanip>
using namespace std;
 
 
int main(){
    int X, a, b;
    cin >> X;
    a = X / 100;
    b = X%100;
    if (b > a * 5){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
    return 0;
}