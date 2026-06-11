#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    int x,zyo,amari;
    cin>>x;
    zyo=x/100;
    amari=x%100;
    if(zyo*5>=amari){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return(0);
}