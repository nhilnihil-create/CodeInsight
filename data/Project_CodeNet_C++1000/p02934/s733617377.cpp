#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;cin>>n;
  double rans=0;
  int a;
  for(int i=0;i<n;i++){
    cin>>a;
    rans+=1.0/a;
  }
  printf("%.10lf\n",1.0/rans);
  return 0;
}