#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int s = N, ans = 0;
  for (int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    if (s >= tmp){
      s = tmp;
      ans++;
    }
  }

  printf("%d\n", ans);
  
}
