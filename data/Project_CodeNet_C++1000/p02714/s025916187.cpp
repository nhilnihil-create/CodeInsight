#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
 
  string s;
  cin >> s;
  long long r=0,g=0,b=0;

  for(int i=0;i<n;i++){
    if(s.at(i) == 'R')r++;
    if(s.at(i) == 'G')g++;
    if(s.at(i) == 'B')b++;
  }

  int cnt = 0;
  for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
      int k = j+(j-i);
      if(k>=n)break;
      if(s.at(i) != s.at(j) && s.at(j) != s.at(k) && s.at(k) != s.at(i))cnt++;
    }
  }
  cout << r*g*b - cnt << endl;
  
  return 0;
}