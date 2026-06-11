#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int l=1, r=l+m;
  while(l < r){
    printf("%d %d\n", l,r);
    l++;r--;
  }
  l=1+m+1, r=l+m-1;
  while(l < r){
    printf("%d %d\n", l,r);
    l++;r--;
  }
  return 0;
}