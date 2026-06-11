#include <iostream>
using namespace std;

#define N 300000

int main(void){
  bool eratos[N];
  eratos[0] = eratos[1] = false;
  for(int i = 2; i < N; i++){ eratos[i] = true; }
  for(int i = 2; i * i < N; i++)
    if(eratos[i])
      for(int j = i + i; j < N; j += i)
        eratos[j] = false;

  while(true){
    int n;
    cin >> n;
    if(n == 0){ break; }

    int ans = 0;
    for(int i = n + 1; i <= 2 * n; i++)
      if(eratos[i])
        ++ans;
    cout << ans << endl;
  }

  return 0;
}