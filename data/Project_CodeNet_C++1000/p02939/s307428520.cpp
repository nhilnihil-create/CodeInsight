#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n=s.size();
  int ans=n;
  for(int i=0;i<n;i++){
    if(s[i]==s[i+1]){
      ans--;
      i+=2;
    }
  }
  cout << ans << endl;
}