#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  int a,b;
  cin >> a >> b;
  
  auto choose = [](int x){
    return (x*(x-1))/2;
  };
  
  printf("%d\n", choose(a) + choose(b));
}