#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,k;
  cin>>N;
  vector<int> X(N);
  for(int i=0; i<N; i++){
    cin>>X.at(i);
  }
  sort(X.begin(),X.end());
  int mini=1000000000;
  for(int i=X.at(0); i<=X.at(N-1); i++){
    int c=0;
    for(int j=0; j<N; j++){
      k=pow(abs(i-X.at(j)),2);
      c+=k;
    }
    mini=min(mini,c);
  }
  cout<<mini<<endl;
}