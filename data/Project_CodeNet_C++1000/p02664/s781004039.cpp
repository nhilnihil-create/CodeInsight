#include<iostream>
using namespace std;
int main() {
  string t;cin>>t;
  int n=t.size();
  int cnt=0;
  for(int i=0;i<n;i++){
    if(t[i]=='?'){
      cout<<'D';
    }else{
      cout<<t[i];
    }
  }
  return 0;
}
