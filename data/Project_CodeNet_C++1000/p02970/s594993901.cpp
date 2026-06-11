#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,D;
  cin>>N>>D;
  if(N%(D*2+1)==0) cout<<N/(D*2+1)<<endl;
  else cout<<N/(D*2+1)+1<<endl;
}