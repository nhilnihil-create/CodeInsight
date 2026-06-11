#include<bits/stdc++.h>
using namespace std ;

 

int main(){
    long long int X,dep;
    dep=100;
    cin>>X;
    long long int t=0;
    while(dep<X){
        dep+=dep/100;
        t++;
    }
    cout<<t;
    return 0;
}