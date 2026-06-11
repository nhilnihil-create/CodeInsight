#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  map<int64_t,int> m;
  int64_t temp;
  for(int i=0;i<N;i++){
    temp=i+1+A.at(i);
    if(m.count(temp)){
      m.at(temp)++;
    }else{
      m[temp]=1;
    }
  }
  int64_t ans=0;
  for(int i=0;i<N;i++){
    temp=i+1-A.at(i);
    if(m.count(temp)){
      ans+=m.at(temp);
    }
  }
  cout << ans << endl;
  return 0;
}
