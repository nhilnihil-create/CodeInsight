#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  double dans=0;
  int n;
  cin >>n;
  rep(i,n){
    double d;
    cin >> d;
    dans+=1/d;
  }
  printf("%.12lf\n",1/dans);
}