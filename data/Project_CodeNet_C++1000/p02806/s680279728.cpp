#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<pair<string,int>> A(N);
  for(pair<string,int> &i:A)
    cin>>i.first>>i.second;
  string X;
  cin>>X;
  bool bo=false;
  int j=0;
  for(pair<string,int> &i:A){
    if(bo)
      j+=i.second;
    else if(i.first==X)
      bo=true;
  }
  cout<<j<<endl;
}