#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int a1=0,b1=0;
    for(int i=1;i<=b;i++){
        a1+=a*pow(10,(i-1));
    }
    for(int i=1;i<=a;i++){
        b1+=b*pow(10,(i-1));
    }
    if(a1>b1)cout<<a1<<endl;
    else cout<<b1<<endl;
    return 0;
}