#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c=0;
    cin>>a;
    a=a%10;
    if(a==2 || a==4 || a==5 || a==7 || a==9){cout<<"hon";return 0;}
    if(a==0 || a==1 || a==6 || a==8){cout<<"pon";return 0;}
    if(a==3){cout<<"bon";}
    return 0;
}
