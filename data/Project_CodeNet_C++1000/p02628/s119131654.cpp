#include <bits/stdc++.h>
using namespace std;
int main() {
  int N ,K;
  cin>>N>>K;
  vector<int> wage(N);
  for(int i=0; i<N; i++){
    cin>>wage.at(i);
  }
  sort(wage.begin(),wage.end());
  int answer=0;
  
  for(int i=0; i<K; i++){
    answer=answer+wage.at(i);
  }
  cout<<answer<<endl;
  
}