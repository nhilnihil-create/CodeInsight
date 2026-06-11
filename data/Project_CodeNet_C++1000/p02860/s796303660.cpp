#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  bool ans=true;
  if(n%2==0){
    for(int i=0;i<n/2;i++){
      if(s.at(i)!=s.at(i+n/2))
        ans=false;
    }
  }else{
    ans=false;
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}