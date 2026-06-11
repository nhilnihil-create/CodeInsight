#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int k, x;
  cin >> k >> x;

  int mi = max(-1000000, x-k+1);
  int ma = min(1000000, x+k-1);

  for(int i=mi; i<=ma; i++){
    cout << i << " ";
  }
}
