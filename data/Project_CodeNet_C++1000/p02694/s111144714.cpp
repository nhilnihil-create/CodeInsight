#include <bits/stdc++.h>
using namespace std;



int main(){
    long long X;
    cin>>X;
    long long Y=100;
    int cou=0;
    while(Y<X){
        Y+=Y/100;
        cou++;
    }
    cout<<cou<<endl;
}