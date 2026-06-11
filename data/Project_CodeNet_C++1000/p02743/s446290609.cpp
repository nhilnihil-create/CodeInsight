#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long double  a,b,c;
    cin >> a >> b >> c;

    long double e = 1.0E-14; 
    if(sqrt(a)+sqrt(b)+ e<sqrt(c)){
        cout << "Yes" << endl;
    }
    else{
       cout << "No" << endl;
    }
} 

