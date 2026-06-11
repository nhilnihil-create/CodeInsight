#include <iostream>
#include <math.h>
#include <string>

using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d=0;
    if(a== b && b!=c){
        d=1;
    }
    if(b== c && c!=a){
        d=1;
    }
    if(c== a && a!=b){
        d=1;
    }
    if(d ){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}