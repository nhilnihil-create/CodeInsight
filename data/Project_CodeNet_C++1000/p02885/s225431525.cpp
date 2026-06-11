#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
if(a>=1&&b>=1&&a<=100&&b<=100){
    if(a<=2*b)
        cout<<0<<endl;
    else
        cout<<(a-2*b)<<endl;
}
return 0;}
