#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
cin>>a>>b>>c;
if(a>=1&&b>=1&&c>=1&&a<=13&&b<=13&&c<=13){
    if((a+b+c)>=22)
        cout<<"bust"<<endl;
    else
        cout<<"win"<<endl;
}


return 0;}
