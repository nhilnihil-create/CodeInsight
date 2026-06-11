#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  ll N;
  cin>>N;
  ll sum = N*(N*N+3*N+2)/6;
  for(int i(0);i<N-1;i++){
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    sum -= a*(N-b+1);
  }
  cout << sum << endl;
  return 0;
}
