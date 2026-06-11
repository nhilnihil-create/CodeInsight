#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, D;
  cin >> N >> D;
  int64_t ans = 0;
  for(int i=0; i<N; i++){
    int64_t x, y;
    cin >> x >> y;
    if(D*D>=x*x+y*y){
      ans++;
    }
  }
  cout << ans << endl;
}
