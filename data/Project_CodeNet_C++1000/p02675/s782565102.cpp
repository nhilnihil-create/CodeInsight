#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    ll n;
    cin>>n;
    
    int a=n%10;
    if(a==2 || a==4 || a==5 || a==7 || a==9){
        cout<<"hon"<<endl;
    }
    else if(a==3){
        cout<<"bon"<<endl;
    }else{
        cout<<"pon"<<endl;
    }
    
}