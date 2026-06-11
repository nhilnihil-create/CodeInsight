#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define All(a) (a).begin(),(a).end()

// Remember v.shrink_to_fit() when erasing

void solve(){
  int n;
  ll a,b,c,cnt=0;
  scanf("%d",&n);
  for(int i=1; i < n; i++){
    for(int j=1; j < n; j++){
      if(i*j>=n)break;
      cnt++;
    }
  }

  



  printf("%lld\n",cnt);
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}