#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=1; i <= (int)(n); i++)

int main(){
  long long A, V, B, W, T;
  cin >> A >> V >> B >> W >> T;
  
  int d = abs(A-B);
  if(V <= W){
  	cout << "NO" << endl;
    return 0;
  }
  int s = V-W;
  if(d <= (long long)s*T) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
