#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<string> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  
  set<string> S;
  
  for(int i=0;i<N;i++){
    S.insert(vec[i]);
  }
  
  cout<<S.size()<<endl;
}