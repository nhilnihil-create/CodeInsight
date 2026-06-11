#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
 string s,t;
 cin>>s>>t;
 int l=s.length();
 int sum=0;
 for(int i=0;i<l;i++){
   if(s[i]!=t[i]){
     sum++;
   }
 }
 cout<<sum<<endl;
}