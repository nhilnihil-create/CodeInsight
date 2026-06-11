#include <bits/stdc++.h>
using namespace std;

int main(){
  string T;
  cin>>T;
  for(int i=0;i<T.length();i++){
    if(T.at(i)=='?'){
      cout<<'D';
    }
    else cout<<T.at(i);
  }
  cout<<endl;
  return 0;
  /*
  T=T+'K';
  int ans=0;
  for(int i=0;i<T.length()-1;i++){
    if(T.at(i)=='D'||T.at(i)=='?'||(T.at(i)=='P'&&T.at(i+1)=='D')||(T.at(i)=='?'&&T.at(i+1)=='D')||(T.at(i)=='P'&&T.at(i+1)=='?')){
      ans++;
    }
  }
  cout<<ans<<endl;
  */
}
