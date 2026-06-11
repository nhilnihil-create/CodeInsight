#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> H(N+1);
  H.at(0) = 0;
  for(int i=1;i<=N;i++){cin >> H.at(i);}
  
  int ans = 0;
  int count = 0;
  for(int i=1;i<=N;i++){
    if(H.at(i)<=H.at(i-1)){
      count++; 
      if(count>ans){ans = count;}}
    
    else{count = 0;}
  }
  
  cout << ans << endl;
}