#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0,now=1,b;
  for(int i=0;i<n;i++){
    cin >> b;
    if(b!=now)
      ans++;
    else
      now++;
  }
  cout << (ans==n?-1:ans) << endl;
  return 0;
}