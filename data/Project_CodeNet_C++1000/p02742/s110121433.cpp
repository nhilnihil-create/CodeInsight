#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int h,w;
  cin >> h >> w;
  if(h == 1 || w == 1){
    printf("1");
    exit(0);
  }
  printf("%lld",(h+w) % 2 ? ((h*w)/2) : (((h*w)+1)/2));
}
