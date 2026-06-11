#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, s;
  cin >> n >> k >> s;
  int s2 = s+1;
  if(s2 > 100000) s2 = 1;
  for(int i=0; i<n; ++i){
    if(i == n-1) printf("%d\n", (i<k ? s:s2));
    else printf("%d ", (i<k ? s:s2));
  }
}