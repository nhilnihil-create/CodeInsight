#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;

int main(){
    double r;
    const double pi = acos(-1);
    
    cin >> r ;
    cout<<fixed<<setprecision(10);
    cout << r*r*pi<<" "<<2*pi*r<<endl;
}
