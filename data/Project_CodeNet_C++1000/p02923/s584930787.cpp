#include <iostream>

using namespace std;

int main(void){

  int N, H[100000];
  int x, ans;

  x = ans = 0;

  cin >> N;
  for(int i=0; i<N; i++){
    cin >> H[i];
  }

  for(int i=0; i<N-1; i++){
    if(H[i]>=H[i+1]) x++;
    else x = 0;
    if(ans<=x) ans = x;
  }

  cout << ans << endl;

  return 0;
}
