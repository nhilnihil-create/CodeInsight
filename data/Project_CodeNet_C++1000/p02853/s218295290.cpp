#include <iostream>
using namespace std;

int main(){
    int x,y;
    int sumx=0,sumy=0;
    cin>>x>>y;
    if (x==1) sumx += 300000;
    else if(x==2) sumx += 200000;
    else if(x==3) sumx += 100000;
    if (y==1) {sumy += 300000;}
    else if(y==2) {sumy += 200000;}
    else if(y==3) {sumy += 100000;}
    else;
    int allsum=sumx+sumy;
    if(x==1 && y==1) allsum = sumx+sumy+400000;
    else;
    
    cout<<allsum<<endl;
    return 0;
    }