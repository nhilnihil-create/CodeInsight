#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,ans;
  cin >>N >> K;
  if (K<2)
    ans=0;
  else
    ans=N-K;
  cout << ans << endl;
}


