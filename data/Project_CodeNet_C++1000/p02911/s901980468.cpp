#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, q, a;
  cin >> n >> k >> q;
  vector<int> vn(n,0);
  for(int i=0; i<q; ++i){
    cin >> a;
    --a;
    ++vn[a];
  }
  for(int i=0; i<n; ++i){
    if(k-q+vn[i] > 0) printf("Yes\n");
    else printf("No\n");
  }
}