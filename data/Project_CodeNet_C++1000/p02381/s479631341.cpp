#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
  int n, s[1000];
  double sum = 0;
  double a = 0;
  while(1){
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; i++){
      cin >> s[i];
      sum += s[i];
    }
    sum /= n;
    for(int i = 0; i < n; i++){
      a += (s[i]-sum) * (s[i]-sum);
    }
    a /= n;
    a = sqrt(a);
    printf("%lf\n", a);
    sum = 0;
    a = 0;
  }
}