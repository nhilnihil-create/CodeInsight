#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;

long long pow_mod(long long a, long long b) {
  long long pow_ans=1;
  while(b) {
    if(b%2==1) {
      pow_ans*=a%mod;
      pow_ans%=mod;
    }
  a=a*a%mod;
  b/=2;
  }
  return pow_ans;
}

int main() {
  int n;
  cin >> n;
  vector<long long> box(n,0);
  for(int i=0;i<n;i++) {
    cin >> box.at(i);
  }
  long long mx=0;
  vector<long long> num_box(n,0);
  for(int i=0;i<n;i++) {
    num_box.at(box.at(i))++;
    mx=max(mx,box.at(i));
    //cout << mx << endl;
  }
  long long ans = 1;
  if(num_box.at(0)!=1||box.at(0)!=0) {
    ans = 0;
  }
  else {
    for(int i=0;i<mx;i++) {
      ans *= (pow_mod(num_box.at(i),num_box.at(i+1)))%mod;
      ans%=mod;
    }
  }
  cout << ans << endl;
}