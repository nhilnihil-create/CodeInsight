#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A;
  cin >> N;
  set<pair<int64_t,int> > sp;
  int64_t ma=1000;
  for(int i=0;i<N;i++){
    cin >> A;
    for(auto & p:sp){
      ma=max(ma,p.first*A+p.second);
    }
    sp.insert(make_pair(ma/A,ma%A));
  }
  cout << ma << endl;
  return 0;
}
