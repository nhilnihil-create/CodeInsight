#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> w(n);
  for(int i=0;i<n;i++){
    cin >> w[i];
  }
  
  int ans=1e9;
  for(int i=0;i<n-1;i++){
    int s1=0,s2=0;
    for(int j=0;j<n;j++){
      if(j<=i) s1+=w[j];
      else s2+=w[j];
    }
    ans = min(ans,abs(s1-s2));
  }
  cout << ans << endl;
}