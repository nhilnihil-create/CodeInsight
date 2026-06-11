#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
cin>>n>>k;
if(n>=1&&n<=100&&k>=1&&k<=pow(10,5)){
if(n*500>=k)
    cout<<"Yes"<<endl;
else if(n*500<k)
    cout<<"No"<<endl;}

return 0;}
