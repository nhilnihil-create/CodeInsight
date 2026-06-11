#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  long double sum = 0l;
  for(int i = 0; i < n; i++){
    long double a; cin >> a;
    sum += 1/a;
  }
  printf("%.8llf",1/sum);
}