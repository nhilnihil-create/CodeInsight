#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
  int n,k;
  int counts = 0;
  cin >> n >> k;
  while(n >= k){
   counts++;
    n /= k;
  }
  cout << counts + 1 << endl;
}
