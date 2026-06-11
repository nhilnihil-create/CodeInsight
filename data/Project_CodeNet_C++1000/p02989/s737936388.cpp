#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int mod = 1000000007;
long long dp[100005];

int main() {
  long long n;
  cin >> n;
  vector<int> d(n);
  
  for(int i = 0;i<n;i++){
    cin >> d[i];
  }
  sort(d.begin(),d.end());
  
  int res = 0;
  
  if(d[n/2-1] != d[n/2]){
    res = d[n/2] - d[n/2-1];
  }
  //cout << d[(n/2)] << " " << d[(n/2)] << endl;
  cout << res << endl;
}
