#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    double ans;
    if(n%2 == 0){
      ans = (double)1/2;
    }else{
      ans = (double)(n/2+1)/n;
    }
    printf("%.10lf\n",ans);
  }
