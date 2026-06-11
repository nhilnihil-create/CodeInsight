#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int N=S.length();
  string str1=S.substr(0,(N-1)/2);
  string str2=S.substr(((N+3)/2)-1,N);
  string R=string(S.rbegin(),S.rend());
  string rev1=string(str1.begin(),str1.end());
  string rev2=string(str2.rbegin(),str2.rend());

 if(S==R&&str1==rev1&&str2==rev2&&N>=3&&N<=99){
     cout<<"Yes";
 }
 else{
     cout<<"No";
 }
   return 0;
}