#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  cin>>S;
  map<int,int> A;
  A[0]++;
  int j=1,k=0;
  for(int i=0;i<S.size();i++){
    k=(k+j*(S[S.size()-1-i]-'0'))%2019;
    A[k]++;
    j=j*10%2019;
  }
  j=0;
  for(pair<int,int> p:A){
    j+=p.second*(p.second-1)/2;
  }
  cout<<j<<endl;
}