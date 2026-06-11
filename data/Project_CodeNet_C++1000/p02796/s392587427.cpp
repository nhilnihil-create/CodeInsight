#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<pair<int,int>> p(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    p.at(i)=make_pair(a+b,a-b);
  }
  sort(p.begin(),p.end());
  int A=p.at(0).first,Z=1;
  for(int i=1;i<N;i++){
    if(A<=p.at(i).second){
      Z++;
      A=p.at(i).first;
    }
  }
  cout<<Z<<endl;
}