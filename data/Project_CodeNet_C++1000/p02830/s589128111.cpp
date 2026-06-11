#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  int N;
  cin>>N>>s>>t;
 if(s.length()==N&&t.length()==N&&N>=1&&N<=100){
     for(int i=0;i<N;i++){
         cout<<s[i]<<t[i];
     }
 }
   return 0;
   
}