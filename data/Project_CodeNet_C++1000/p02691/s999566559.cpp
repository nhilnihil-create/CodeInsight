#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int main(){
  lli n;
  cin >> n;
  vector<lli> vec(n), arr(n);
  for(int i=0;i<n;i++){
    cin >> vec[i];
    arr[i] = vec[i] + i+1;
  }
  sort(arr.begin(), arr.end());
  lli ans = 0;
  for(int i=0;i<n;i++){
    ans+=distance(
      lower_bound(arr.begin(), arr.end(), i+1 - vec[i]),
      lower_bound(arr.begin(), arr.end(), i+2 - vec[i])
    ) ;
  }
  cout << ans;
}