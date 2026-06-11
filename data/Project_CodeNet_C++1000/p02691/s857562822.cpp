#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t>data(N);
  for(int i=0;i<N;i++){
    cin >> data.at(i);
  }
  vector<int64_t>syu(N);
  for(int i=0;i<N;i++){
    if(i+1>=data.at(i)) syu.at(i+1-data.at(i))++;
  }
  int64_t ans=0;
  for(int i=0;i<N;i++){
    if(data.at(i)+i+1<N) ans+=syu.at(data.at(i)+i+1);
  }
  cout << ans << endl;
}