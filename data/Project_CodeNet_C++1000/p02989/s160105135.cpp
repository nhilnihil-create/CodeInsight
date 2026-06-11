#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  
  vector<int> d(N);
  for(int i = 0; i < N; i++) cin >> d.at(i);
  sort(d.begin(), d.end());
  
  int A = d.at(N/2-1);
  int B = d.at(N/2);
  
  cout << B - A << endl;
  
}