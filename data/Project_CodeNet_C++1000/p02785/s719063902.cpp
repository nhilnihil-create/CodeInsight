#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,k;
  cin >> n >> k;
  vector<long long> t(n);
  long long ans = 0;
  for(int i = 0; i < n; i++){
    cin >> t[i];
  }
  sort(t.begin(),t.end(),greater<long long>());
  for(int i = k; i < n; i++){
    ans += t[i];
  }
  cout << ans << endl;
}