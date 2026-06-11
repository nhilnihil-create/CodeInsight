#include <bits/stdc++.h>
using namespace std; 

int main() {
  string s;
  cin>>s;
  int n=s.size();
  string tmp="";
  int kotae=0;
  for(int i=0;i<n;i++){
    int count=1;
    string a=s.substr(i,count);
    if(tmp==a){
      while(tmp==a){
        count++;
        a=s.substr(i,count);
        i+=count-1;
      }
    }
    //cout<<a<<" ";
    if(i+1>n)break;
    kotae++;
    count=1;
    tmp=a;
  }
  cout<<kotae<<endl;
  return 0;
}
      

