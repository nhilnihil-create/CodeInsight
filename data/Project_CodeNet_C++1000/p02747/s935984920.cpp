#include<bits/stdc++.h>
using namespace std;
int main(){
string s1,s2="";
cin>>s1;
for(int i=0;i<5;i++){
s2 = s2 + "hi";
if(s2 == s1) {
  cout<<"Yes"<<endl;
  return 0;
}
}
cout<<"No"<<endl;
} 