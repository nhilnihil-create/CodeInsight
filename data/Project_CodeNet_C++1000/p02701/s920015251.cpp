#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<string>vec(N);
  set<string>se;
  for(int i=0;i<N;++i){
    cin>>vec.at(i);
    se.insert(vec.at(i));
  }
  cout<<se.size()<<endl;
}