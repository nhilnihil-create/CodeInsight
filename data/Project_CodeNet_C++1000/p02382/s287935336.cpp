#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void){
    long double d, e, f, b;
    int a;
    long c=0,Z=0;
    cin >> a;
    long double A[a], X[a], Y[a];
    for(int i=0; i<a; i++){
        cin>>b;
        X[i]=b;
    }
    for(int i=0; i<a; i++){
        cin>>b;
        Y[i]=b;
    }
    for(int i=0; i<a; i++){
        c+=fabs(X[i]-Y[i]);
    }
    cout << setprecision(16) << c <<endl;
    c=0;
    for(int i=0; i<a; i++){
        c+=pow(fabs(X[i]-Y[i]),2);
    }
    cout << setprecision(16) <<sqrt(c)<<endl;
    c=0;
    for(int i=0; i<a; i++){
        c+=pow(fabs(X[i] - Y[i]),3);
    }
    cout << setprecision(16) << pow(c,0.33333333333333333333333) <<endl;
    c=0;
    for(int i=0; i<a; i++){
        if(fabs(X[i]-Y[i])>Z){
            Z=fabs(X[i]-Y[i]);
        }
    }
    cout << setprecision(16) << Z <<endl;
    return 0;
}
