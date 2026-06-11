#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,M,V,P,Z=1,A=0;
  cin>>N>>M>>V>>P;
  vector<int64_t> p(N);
  for(int64_t i=0;i<N;i++){
    cin>>p.at(i);
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  for(int64_t i=1;i<N;i++){
    if(p.at(i)==p.at(i-1)||i<P){
      Z++;
    }
    else{
      if(p.at(P-1)-p.at(i)<=M&&M*(N-(i-P+1))+A+(p.at(i)+M-p.at(P-1))*(i-P+1)>=M*V){
        Z++;
      }
      else{
        break;
      }
    }
    if(p.at(i)<p.at(P-1)){
      A+=p.at(P-1)-p.at(i);
    }
  }
  cout<<Z<<endl;
}