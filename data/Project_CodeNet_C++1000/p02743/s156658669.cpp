#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    long double a,b,c;
    cin >> a >> b >> c;

    long long int hiki;
    hiki = c-(a+b);
    if(hiki>0 && hiki*hiki>4*a*b){
        cout << "Yes" ;
    }else{
        cout << "No";
    }
    return 0;
}