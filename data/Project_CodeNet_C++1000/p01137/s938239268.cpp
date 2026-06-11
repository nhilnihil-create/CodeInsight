#include <cstdio>
#include <algorithm>
using namespace std;

int E;

int solve(){
  int ans = 1000000;
  for(int z = 0; z * z * z <= E; ++z){
    int F = E - z * z * z;
    for(int y = 0; y * y <= F; ++y){
      int x = F - y * y;
      ans = min(ans, x + y + z);
    }
  }
  return ans;
}

int main(){
  while(scanf("%d", &E) && E > 0){
    printf("%d\n", solve());
  }
}