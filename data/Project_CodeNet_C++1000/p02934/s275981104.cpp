#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  double a,s=0; for(int i=0;i<n;i++) cin>>a,s+=1/a;
  printf("%.9lf",1/s);
}