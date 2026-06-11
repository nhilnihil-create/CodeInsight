#include <cstdio>

using namespace std;

bool count[30];

int main(){
  for(int i = 0; i < 30; i++){
    count[i] = true;
  }
  for(int i = 0; i < 28; i++){
    int a;
    scanf("%d", &a);
    count[a - 1] = false;
  }
  for(int i = 0; i < 30; i++){
    if(count[i]){
      printf("%d\n", i + 1);
    }
  }
  return 0;
}