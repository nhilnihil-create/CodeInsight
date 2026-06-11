#include <iostream>
 
using namespace std;
 
int main(){
  int N, ans=0;
  cin >> N;
  int X[N];
  for(int i=0; i<N; i++){
    cin >> X[i];
    ans += 100 * 100;
  }

  for(int P=1; P<101; P++){
    int tmp=0;
    for(int i=0; i<N;i++){
      tmp += (X[i]-P) * (X[i]-P);
    }
    if(ans > tmp){
      ans = tmp;
    }
  }

  printf("%d\n", ans);
}
