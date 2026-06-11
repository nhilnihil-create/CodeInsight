#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M;
cin>>N>>M;
if(N>=0&&N<=100&&M>=0&&M<=100&&(N+M)>=2){
cout<<((N*(N-1))/2 + (M*(M-1))/2)<<endl;}

return 0;}
