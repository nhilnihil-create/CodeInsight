#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin>>s;
  int l=s.length();
  for(int i=0;i<l;i++){
   // if(s.at(i)=='?' && s.at(i+1)=='D') 
     // s.at(i)='P'; 
    //if(s.at(i)=='?'&& s.at(i+1)=='?') {
      //s.at(i)='P';
      //s.at(i+1)='D';
    
    if(s.at(i)=='?')
      s.at(i)='D';
  }
    cout<<s;
}
