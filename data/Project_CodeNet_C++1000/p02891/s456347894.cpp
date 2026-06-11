#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t K;
  string S;
  cin>>S>>K;
  int64_t N=S.size(),Z=0,P=1;
  vector<int> p;
  for(int i=1;i<N;i++){
    if(S.at(i-1)==S.at(i)){
      P++;
    }
    else{
      p.push_back(P);
      P=1;
    }
  }
  p.push_back(P);
  if(p.size()==1){
    Z+=N*K/2;
  }
  else if(S.at(0)==S.at(N-1)){
    for(int i=1;i<p.size()-1;i++){
      Z+=p.at(i)/2*K;
    }
    Z+=p.at(0)/2+p.at(p.size()-1)/2;
    Z+=((p.at(0)+p.at(p.size()-1))/2)*(K-1);
  }
  else{
    for(int i=0;i<p.size();i++){
      Z+=p.at(i)/2*K;
    }
  }
  cout<<Z<<endl;
}


