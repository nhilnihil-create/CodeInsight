#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
 string s;
 cin>>s;
 int n=s.length();
 int cnt=0;
 for(int i=0;i<n/2;i++){
   if(s[i]!=s[n-1-i]){
     cnt++;
   }
 }
 cout<<cnt<<endl;
}