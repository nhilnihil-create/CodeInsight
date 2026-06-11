#include <bits/stdc++.h>
using namespace std;

int main(){
  long N,M,L =1; cin >> N >> M;
  long a[N]; 
  for (int i =0; i<N; i++) {
    cin >> a[i]; a[i] /=2; L = lcm(L,a[i]);
  }

  for (int i =0; i<N; i++) {
    if (L / a[i] % 2 ==0) {
      cout << 0 << endl;
      return 0;
    }
  }
  long ans;
  if (M % (2*L) >=L) ans = M / (2*L) + 1;
  else ans = M/(2*L);
  cout << ans <<endl;                   
}