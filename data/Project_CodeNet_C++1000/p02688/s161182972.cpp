#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  map<int,int>ok;
  int b,c;
  for(int i=0;i<k;i++){
    cin >> b;
    for(int j=0;j<b;j++){
      cin >> c;
      ok[c-1]=1;
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(ok[i]==1)
      ans++;
  }
  cout << n-ans << endl;
  return 0;
}