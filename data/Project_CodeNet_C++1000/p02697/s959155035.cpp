#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  if(n%2){
    int l = 1, r = n;
    for(int i=0; i<m; ++i){
      printf("%d %d\n",l,r);
      ++l;
      --r;
    }
  }else{
    int l=1, r = n-1;
    bool frag = true;
    for(int i=0; i<m; ++i){
      if(frag && r-l <= n/2){
        frag = false;
        ++l;
      }
      printf("%d %d\n",l,r);
      ++l;
      --r;
    }
  }
}