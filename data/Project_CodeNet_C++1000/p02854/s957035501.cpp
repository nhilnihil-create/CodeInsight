#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<long long> p(n);
  long long s = 0;
  for(int i = 0; i < n; i++){
    cin >> p[i];
    s += p[i];
  }
  long long sum = 0;
  long long ans = s;
  for(int i = 0; i < n; i++){
    sum += p[i];
    ans = min(ans, abs(sum - (s - sum)));
  }
  cout << ans << endl;
}