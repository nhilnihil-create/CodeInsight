#include <iostream>
#include <cmath>
 
using namespace std;
 
int main(){
  int N, ans;
  cin >> N;

  ans = ceil(N / 1.08);
  if(N == floor(ans * 1.08)){
    printf("%d\n",ans);
  }else{
    printf(":(\n");
  }
  
}
