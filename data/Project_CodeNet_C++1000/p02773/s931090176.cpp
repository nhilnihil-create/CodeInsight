#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string>S(N);
  for(int i=0; i<N; i++)cin >> S.at(i);
  
  sort(S.begin(), S.end());
  int count=1;
  int maxim=1;
  
  for(int i=0; i<N-1; i++){
    if(S.at(i)==S.at(i+1))count++;
    else count =1;
    maxim = max(count, maxim);
  }
  
  count =1;
  
  for(int i=0; i<N-1; i++){
    if(S.at(i)==S.at(i+1))count++;
    else count=1;
    if(count==maxim)cout << S.at(i) << endl;
  }
  
  if(maxim==1)cout << S.at(N-1) << endl;
}