#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k;
  cin>>n>>k;
  vector<int> flag(n);
  vector<int> treat(k);
  for(int i=0;i<k;i++){
    cin>>treat.at(i);
    vector<int> candy(treat.at(i));
    for(int j=0;j<treat.at(i);j++){
      cin>>candy.at(j);
    }
    for(int m=0;m<treat.at(i);m++){
      flag.at(candy.at(m)-1)=1;
    }
  }
  int x=n;
  for(int l=0;l<n;l++){
    x=x-flag.at(l);
  }
  cout<<x;
}