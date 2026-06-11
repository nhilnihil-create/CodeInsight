#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
  long int h, n, a, total=0;
  cin >> h >> n;
  rep(i,n){
    cin >> a;
    total += a;
  }
  cout << (total>=h?"Yes":"No") << endl;
  return 0;
}
