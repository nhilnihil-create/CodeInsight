#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  
  vector<int> vec(0);
  while(N>=K){
    int a=N%K;
    vec.push_back(a);
    N=N/K;
  }
  vec.push_back(N);
  reverse(vec.begin(),vec.end());
  
  cout<<vec.size()<<endl;
}