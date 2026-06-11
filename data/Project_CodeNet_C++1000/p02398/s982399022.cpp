#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;


int main(){
  int a,b,c,s;
  s = 0;
  cin >> a >> b >> c;
  for(int i = a; i < b+1;i++){
    if(c % i == 0) s++;
  }
  printf("%d\n",s);

  return 0;
}
