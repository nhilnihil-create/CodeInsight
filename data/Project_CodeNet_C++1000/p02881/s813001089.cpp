#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N;
  cin >> N;
  
  ll num = pow(N, 0.5);
  while (N % num != 0){
    num--;
  }
  
  ll ans = num + N / num -2;
  cout << ans << endl;
}