#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  int v[N];
  for (int i = 0; i < N; i++){
    cin >> v[i];
  }
  sort(v, v+N);

  float ans = v[0];
  for (int i = 1; i < N; i++){
    ans = (float)(ans + v[i]) / 2;
  }
  printf("%f\n", ans);
}
