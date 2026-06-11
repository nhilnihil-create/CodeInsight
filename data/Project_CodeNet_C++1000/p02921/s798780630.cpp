#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0,x=0;
    string s;
    string t;
    cin>>t>>s;
    for(int i=0;i<3;i++){
        if(s[i]==t[i]){x++;}
    }
    cout<<x;
    return 0;
}
