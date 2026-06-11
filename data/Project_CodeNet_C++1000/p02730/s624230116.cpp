#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  string s;
  cin >> s;
  int n=s.size();
  string ans="Yes";
  if(n==3 && s[0]==s[2]){
    cout << ans << endl;
    return 0;
  }
  else if(n==3 && s[0]!=s[2]){
    cout << "No" << endl;
    return 0;
  }
  int i=0,j=n-1;
  while(i<j){
    if(i==j) break;
    if(s[i]!=s[j]){
      cout << "No" << endl;
      return 0;
    }
    i++;
    j--;
  }
  i=0;
  j=n/2-1;
  while(i<j){
    if(s[i]!=s[j]){
      cout << "No" << endl;
      return 0;
    }
    i++;
    j--;
  }
  i=n/2+1;
  j=n-1;
  while(i<j){
    if(s[i]!=s[j]){
      cout << "No" << endl;
      return 0;
    }
    i++;
    j--;
  }
  cout << ans << endl;
  return 0;
}
