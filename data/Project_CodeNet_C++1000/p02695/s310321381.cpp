#include <bits/stdc++.h>
using namespace std;


int score(int table[][4], int* a, int q) {
  int ans = 0;
  for(int i=0; i<q; i++) {
    if(a[table[i][1]] - a[table[i][0]] == table[i][2]) ans += table[i][3];
  }

  return ans;
}

int main() {
  int n,m,q;
  cin>>n>>m>>q;
  int table[q][4];
  for(int i=0; i<q; i++) {
    cin>>table[i][0]>>table[i][1]>>table[i][2]>>table[i][3];
  }

  int a[n+1];
  for(int i=0; i<=n; i++) a[i]=1;
  int ans = score(table, a, q);
  while(1) {
    a[n]++;
    if(a[n]>m) {
      int check = n-1;
      while(a[check]==m) check--;
      a[check]++;
      for(int i=check+1; i<=n; i++) a[i]=a[check];
    }
    if(a[0]>1) break;

    ans = max(ans, score(table, a, q));
  }

  cout<<ans<<endl;

  return 0;
}