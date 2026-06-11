#include <cstdio>
#include <iostream>

using namespace std;

int main (){
  int n,a,ans = 0;
  scanf("%d",&n);
  for(int i = 1;i <= n;i++){
    scanf("%d",&a);
    if(i%2 == 1 && a%2 == 1) ans++;
  }
  printf("%d",ans);
  return 0;
}