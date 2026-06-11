#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N; cin >> N;
  ll ans = 0;
  if(N%2!=0){
    ans = 0;
  } else { 

    N /= 2;

    ll num = 0;
    while(N>0){
      num += N / 5;
      N /= 5;
    }

    ans = num;
  }
  cout << ans << endl;
}
