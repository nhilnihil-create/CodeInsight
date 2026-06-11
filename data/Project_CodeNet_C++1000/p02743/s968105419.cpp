#include<iostream>
#include<cmath>
using namespace std;
int main(){
  long long a, b, c;
  cin >> a >> b >> c;
  if(c-a-b > 0 && 4*a*b < (c-a-b)*(c-a-b)) printf("Yes");
  else printf("No");
  return 0;
}