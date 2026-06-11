#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  sort(an.begin(),an.end());
  double ans = an[0];
  for(int i=1; i<n; ++i){
    ans = (ans + an[i]) /2;
  }
  printf("%.10f\n",ans);
}