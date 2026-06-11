#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x,l;
  cin >> N;
  vector<pair<int, int>> r(N);
  for(int i=0; i<N; i++){
    cin >> x >> l;
    r[i] = make_pair(x+l, x-l);
  }
  sort(r.begin(), r.end());
  int c=0,p=-1e9;
  for(int i=0; i<N; i++){
    if(p <= r[i].second){
      c++;
      p = r[i].first;
    }
  }
  cout << c;
  return 0;
}