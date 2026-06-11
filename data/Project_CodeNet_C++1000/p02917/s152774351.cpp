//MISHON69
//DATE:6/22/2020
#include<bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin>>n;
  int b[n-1];
  FOR(i,n-1){
    cin>>b[i];
  }
  vector<int>a;
  a.push_back(b[0]);
  for(int i=1;i<n-1;i++){
    if(b[i]>=b[i-1])
      a.push_back(b[i-1]);
    else
      a.push_back(b[i]);
  }
  a.push_back(b[n-2]);
  cout<<accumulate(a.begin(),a.end(),0)<<endl;
}  
