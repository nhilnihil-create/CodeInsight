#include <bits/stdc++.h>
using namespace std;

int main(){
  int maxa, maxb, m;
  cin >> maxa >> maxb >> m;
  
  vector<int> pa(maxa), pb(maxb);
  
  int mpa=1000000, mpb=1000000;
  
  for(int i=0; i<maxa; i++){
    cin >> pa[i];
    mpa = min(mpa, pa[i]);
  }
  
  for(int i=0; i<maxb; i++){
    cin >> pb[i];
    mpb = min(mpb, pb[i]);
  }
  
  int minp = mpa + mpb;
  
  int x,y,c;
  for(int i=0; i<m; i++){
    cin >> x >> y >> c;
    minp = min( minp, pa[x-1] + pb[y-1] - c);
  }
  
  cout << minp << endl;
  
  return 0;
}