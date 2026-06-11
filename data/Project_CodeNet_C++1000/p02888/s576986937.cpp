#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  sort(p.begin(), p.end());
  p.push_back(10000);
  for(int i=0;i<N;i++){
    for(int k=i+1;k<N;k++){
      int A=p[i]+p[k];
      int b=lower_bound(p.begin(),p.end(),A)-p.begin();
      Z+=b-k-1;
    }
  }
  cout<<Z<<endl;
}