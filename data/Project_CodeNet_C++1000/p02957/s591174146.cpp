#include<bits/stdc++.h>
using namespace std;
int main(void){
int a,b,m;cin>>a>>b;
m = max(a,b);
if(abs(a-b)%2==0)
    cout<<m-(abs(a-b)/2)<<endl;
else
    cout<<"IMPOSSIBLE"<<endl;
return 0;}
