#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  int n;
  ll sum=0;
  cin >> n;
  rep(i, n){
    if((i+1)%3==0||(i+1)%5==0){
      continue;
    }
    else{
      sum+=i+1;
    }
  }

  cout << sum << endl;

  return 0;
}