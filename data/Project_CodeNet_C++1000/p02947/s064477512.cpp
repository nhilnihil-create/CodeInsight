#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
  int N, i;
  long long Sum = 0;
  string s;
  map<string, long long> S;
  cin >> N;
  
  for(i=0; i<N; i++){
    cin >> s;
    sort(s.begin(), s.end());
    S[s]++;
  }
  
  for(auto p : S){
    Sum += p.second * (p.second - 1) / 2;
  }
  cout << Sum << endl;
  return 0;
}