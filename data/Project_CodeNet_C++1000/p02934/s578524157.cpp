#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n;
cin >> n;
  double sum = 0;
rep(i,n){
  double x;
  cin >> x;
  double y = 1/x;
  sum += y;
}
 printf("%.10f\n",1/sum);
}
  
