#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int n = s.size(), ans = 0;
  if (n%2 == 0){
    for (int i=0 ; i<n/2 ; i++){
      if (s.at(i) != s.at(n-1-i))
        ans++;
    }
  }
  else{
    for (int i=0 ; i<(n-1)/2 ; i++){
      if (s.at(i) != s.at(n-1-i))
        ans++;
    }
  }
  
  cout << ans << endl;
}