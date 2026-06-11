#include <iostream>
using namespace std;

int main(){
 int M, D, res = 0;
 cin >> M >> D; 
 for(int m = 1; m <= M; m++){
  for(int d = 1; d <= D; d++){
   if(d % 10 >= 2 && d / 10 >= 2 && (d % 10) * (d / 10) == m)
     res++;
  }
 }
 cout << res << '\n';
}