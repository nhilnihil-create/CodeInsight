#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int n = s.size();
  vector<long long int> ct(2019);
  vector<long long int> t(n+1);
  
  t[n] = 0;
  ct[0]++;
  long long int base=1;
  for(int i=0; i<n; i++){
    t[n-i-1] = t[n-i] + (s[n-i-1]-'0')*base;
    t[n-i-1] %= 2019;
    base *= 10;
    base %= 2019;
    ct[t[n-i-1]]++;
    //cout << "->" << t[n-i-1]<<endl;
  }
  
  long long int ans=0;
  for(int i=0; i<2019; i++){
    ans += ct[i]*(ct[i]-1)/2;
  }
  
  cout << ans << endl;
}
