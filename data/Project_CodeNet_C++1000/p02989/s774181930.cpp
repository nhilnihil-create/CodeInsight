#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> D(N);
  for(int i=0;i<N;i++){
    cin >> D.at(i);
  }
  sort(D.begin(),D.end());
  cout << D.at(N/2)-D.at(N/2-1) << endl;
}