#include <iostream>

using namespace std;

int main(){
  int N, X, Y;
  cin >> N >> X >> Y;
  int ans[N];
  for (int i = 0; i < N; i++){
    ans[i] = 0;
  }
  X--;
  Y--;

  for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
      if (i <= X && X <= j && i <= Y && Y <= j){
        ans[j - i - (Y - X) + 1]++;
      }else if(X <= i && i <= Y && Y <= j){
        int tmp;
        if (Y-i > i-X) {
          tmp = i - X;
        }else{
          tmp = Y - i;
        }
        
        tmp = (j - Y) + tmp + 1;
        if (tmp <= j-i) {
          ans[tmp]++;
        }else{
          ans[j-i]++;
        }
      }else if(i <= X && X <= j && j <= Y){
        int tmp;
        if (Y-j > j-X) {
          tmp = j - X;
        }else{
          tmp = Y - j;
        }

        tmp = (X - i) + tmp + 1;
        if (tmp <= j-i){
          ans[tmp]++;
        }else{
          ans[j-i]++;
        }
      }else if(X < i && j < Y){
        int tmp = (i - X) + (Y - j) + 1;
        
        if (tmp <= j-i){
          ans[tmp]++;
        }else{
          ans[j-i]++;
        }

      }else{
        ans[j-i]++;
      }
    }
    
  }
  
  for (int i = 1; i < N; i++){
    printf("%d\n", ans[i]);
  }
  
}
