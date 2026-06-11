#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  ll ans=N-1;
  for(int i=1;i<=sqrt(N);i++){
    if(N%i!=0){
      continue;
    }
    ans=min(ans,i+N/i-2);
  }
  cout << ans << endl;
}