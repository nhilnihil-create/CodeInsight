#include<bits/stdc++.h>
using namespace std;
int main(void){
int x,y,z;cin>>x>>y>>z;
cout<<min(min(x+y,x+z),(y+z))<<endl;
return 0;}
