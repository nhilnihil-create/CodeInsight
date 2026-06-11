#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c,d=0,e=0,i=0;
    string s;
    cin>>s;
    if(s[0]=='S' && s[1]=='U'){cout<<'7'; return 0;}
    if(s[0]=='M'){cout<<'6'; return 0;}
    if(s[0]=='T' && s[1]=='U'){cout<<'5'; return 0;}
    if(s[0]=='W'){cout<<'4'; return 0;}
    if(s[0]=='T' && s[1]=='H'){cout<<'3'; return 0;}
    if(s[0]=='F'){cout<<'2'; return 0;}
    if(s[0]=='S' && s[1]=='A'){cout<<'1'; return 0;}
    return 0;
}
