#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  sort(an.begin(),an.end());
  int ans = 0;
  for(int i=0; i<n; ++i){
    if(i == 0 && an[i] > 0) ans -= an[0];
    else if(i == n-1 && an[i] < 0) ans += an[n-1]; 
    else ans += abs(an[i]);
  }
  cout << ans << endl;
  for(int i=n-2; an[i]>=0 && i>0; --i){
    printf("%d %d\n", an[0], an[i]);
    an[0] -= an[i];
  }
  for(int i=1; an[i]<0 && i<n-1 ; ++i){
    printf("%d %d\n", an[n-1], an[i]);
    an[n-1] -= an[i];
  }
  printf("%d %d\n", an[n-1], an[0]);
}