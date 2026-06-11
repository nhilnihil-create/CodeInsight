#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int a=0;
  for(int i=0;i<n-1;++i) if(s[i]!=s[i+1]) a++;
  int ans=n-1-max(a-k*2,0);
  cout << ans << endl;
  return 0;
}
