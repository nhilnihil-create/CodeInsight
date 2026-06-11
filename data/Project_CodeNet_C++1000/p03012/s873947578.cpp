#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,sum=0;
  cin >>n;
  vector<int> w(n),an(n);
  for(int i=0;i<n;++i){
    cin>>w[i];
    sum+=w[i];
    if(i!=0)
      w[i]+=w[i-1];
  }
      an[0]=w[0];
  int mi=1000000;
  for(int i=0;i<n;++i){
    mi=min(mi,abs(w[i]-(sum-w[i])));
  }
  cout<<mi<<endl;
}