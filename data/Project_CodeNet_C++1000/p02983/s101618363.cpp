#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  ll l,r;
  cin >> l >> r;
  int a=l%2019;
  int b=r%2019;
  int min=2019;
  if(l/2019<r/2019 || l%2019==0 || r%2019==0){
    cout << 0 << endl;
    return 0;
  }
  else {
    for(int i=a;i<b;i++){
      for(int j=i+1;j<b+1;j++){
        if(((i%2019)*(j%2019))%2019<min)
        min=((i%2019)*(j%2019))%2019;
      }
    }
  }
  cout << min << endl;
}
