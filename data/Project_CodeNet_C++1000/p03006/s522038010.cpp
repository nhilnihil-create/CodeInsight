#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> x(N),y(N);
  for(int i=0;i<N;i++){
    cin >> x.at(i) >> y.at(i);
  }
  map<pair<int64_t,int64_t>,int> m;
  int ma=0;
  pair<int64_t,int64_t> temp;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j){
        continue;
      }
      temp=make_pair(x.at(j)-x.at(i),y.at(j)-y.at(i));
      if(m.count(temp)){
        m.at(temp)++;
      }else{
        m[temp]=1;
      }
      ma=max(ma,m.at(temp));
    }
  }
  cout << N-ma << endl;
  return 0;
}
