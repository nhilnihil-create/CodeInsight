#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  string s;
  cin >> n >> k >> s;
  int cnt=0;
  for(int i=0;i<n-1;i++){
    if(s.at(i) == s.at(i+1)){
      cnt++;
    }
  }
  
  cout << min(n-1,cnt+2*k) << endl;
  
  return(0);
}