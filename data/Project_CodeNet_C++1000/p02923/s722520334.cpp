#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  long long H[N];
  for (int i = 0; i < N; i++){
    cin >> H[i];
  }

  int max_s=0, s=0;
  for (int i = 1; i < N; i++){
    if (H[i-1] >= H[i]) s++;
    else if(max_s < s){
      max_s = s;
      s = 0;
    }else{
      s = 0;
    }
  }
  max_s = max(max_s, s);
  printf("%d\n", max_s);
  
}
