#include<bits/stdc++.h>
using namespace std;
int main(){
int k,a,b;
bool c =0;
cin>>k>>a>>b;
if(a>=1&&b>=a&&b<=1000&&k>=1&&k<=1000){
    int n =0 ;
    while(true){
        n+=k;
        if(n>=a&&n<=b)
            {c = 1;break;}
        if(n>b)
            break;
    }
    if(c==1)
        cout<<"OK"<<endl;
    else if(c==0)
        cout<<"NG"<<endl;

    }
return 0;}
