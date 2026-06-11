#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll n,k;
  cin >> n >> k;
  int con=0;
  while(n>=k){
    n=n/k;
    con++;
  }
  con++;
  cout << con << endl;
  return 0;

}
