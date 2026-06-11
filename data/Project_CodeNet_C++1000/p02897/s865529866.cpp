#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,c,d=0,e=0,z=0,x=0;
    int b=0;
    cin>>a;
    for(int i=0;i<a;i++){
        b++;
        if(b%2!=0){x++;}
    }
    cout<<x/a;
    return 0;
}
