#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c,d=0,e=0;
    cin>>a;
    for(a;a>0;){
        if(a%10==7){cout<<"Yes"; return 0;}
        a/=10;
    }
    cout<<"No";
    return 0;
}
