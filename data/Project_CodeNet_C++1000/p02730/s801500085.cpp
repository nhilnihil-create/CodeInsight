#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.size(),count=0;
 string t(s.rbegin(),s.rend());
  if(s==t){
    count++;
 
  }
   string sub=s.substr(0,(n-1)/2);

  string q(sub.rbegin(),sub.rend());
  if(sub==q){
   count++;

  }
string sn=s.substr((n+2)/2);
  string w(sn.rbegin(),sn.rend());
  if(w==sn){
count++;

  }
  if(count==3) cout<<"Yes"<<endl;
else cout<<"No"<<endl;
  return 0;
}