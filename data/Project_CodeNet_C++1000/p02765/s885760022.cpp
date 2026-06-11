#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll N = 0,K = 0;
  cin >> N >> K;
  if(N >=10){
    cout << K;
  }
  else{
    cout << K + 100 * (10 - N);
  }
}