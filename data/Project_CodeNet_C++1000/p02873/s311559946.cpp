#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  long long n, r, l;
  r = 0; l = 0;
  n = S.size();
  vector<long long> right(n+1), left(n+1);
  left[0] = 0;
  for(int i=0; i<n; i++){
    if(S[i] == '<') l++;
    else l=0;
    left[i+1] = l;
  }
  right[n] = 0;
  for(int i=n-1; i>=0; i--){
    if(S[i] == '>') r++;
    else r=0;
    right[i] = r;
  }
  long long ans=0;
  for(int i=0; i<=n; i++){
    ans += max(left[i], right[i]);
  }
  cout << ans;
  return 0;
}