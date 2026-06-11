/*
* ID: juryc
* PROG: Round One
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n; cin>>n;
string s,t; cin>>s>>t;
string g="";
for(int i=0;i<n;i++){
g=g+s[i]; g=g+t[i]; 
}
cout<<g<<"\n"; 
return 0;
}