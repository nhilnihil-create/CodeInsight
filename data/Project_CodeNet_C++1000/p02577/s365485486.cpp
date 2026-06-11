#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans=0,n=0;
  string N;
  cin >> N;

  for(int i=0;i<N.size();i++){
    n=N.at(i)-'0';
    ans+=n;
    ans%=9;
  }

  if(ans){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }

  return 0;
}