#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cnt=1;
  cin >> n;
  vector<string> S(n);
  for(int i=0;i<n;i++)cin >> S[i];
  sort(S.begin(),S.end());
  for(int i=1;i<n;i++)if(S[i-1]!=S[i])cnt++;
  cout << cnt << endl;
}
