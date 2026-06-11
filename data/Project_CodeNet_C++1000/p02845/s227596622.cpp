#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  int i;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  long const mod = 1000000007;
  vector<int>numbers(100001,0);
  long ans = 1;
  for(i=0;i<n;i++){
    if(a[i] == 0){
      ans *= 3-numbers[0];
      ans %= mod;
      numbers[0]++;
    }else{
      ans *= numbers[a[i]-1]-numbers[a[i]];
      ans %= mod;
      numbers[a[i]]++;
    }
  }
  cout << ans << endl;
}
