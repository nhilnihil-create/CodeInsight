#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  vector<int>ans(s.size(),0);
  int a=0,b=0;
  for(int i=0,l=s.size();i<l;i++){
    if(s.at(i)=='R'){
      if(i%2==0)
        a++;
      else
        b++;
    }else{
      if(i%2==0){
        ans.at(i)+=a;
        ans.at(i-1)+=b;
      }else{
        ans.at(i)+=b;
        ans.at(i-1)+=a;
      }
      a=0,b=0;
    }
  }
  for(int i=s.size()-1;i>=0;i--){
    if(s.at(i)=='L'){
      if(i%2==0)
        a++;
      else
        b++;
    }else{
      if(i%2==0){
        ans.at(i)+=a;
        ans.at(i+1)+=b;
      }else{
        ans.at(i)+=b;
        ans.at(i+1)+=a;
      }
      a=0,b=0;
    }
  }
  for(int i=0,l=s.size();i<l;i++){
    cout << ans.at(i);
    if(i==l-1)
      cout << '\n';
    else
      cout << ' ';
  }
  return 0;
}