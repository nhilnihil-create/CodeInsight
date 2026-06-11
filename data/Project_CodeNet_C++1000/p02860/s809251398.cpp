#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<char> s(n);
  for(int i=0;i<n;i++)cin >> s[i];
  if(n==1 || n%2==1){
    cout << "No" << endl;
    return 0;
  }
  int j=n/2;
  for(int i=j;i<n;i++){
    if(s[i-j]!=s[i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
