#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int n,i,t[53],ans=0;
  string s[53],x;
  
  cin >> n;
  for (i=0;i<n;i++) cin >> s[i] >> t[i];
  cin >> x;
  
  i=0;
  while (s[i]!=x) i++;
  
  i++;
  while (i<n){
    ans+=t[i];
    i++;
  }
  
  cout << ans << endl;
  
  return 0;
}