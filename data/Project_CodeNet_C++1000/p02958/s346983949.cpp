#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin>>P.at(i);
  }
  int k=0;
  for(int j=0;j<N;j++){
    if(P.at(j)!=j+1) k++;
  }
  if (k<=2) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 
}