#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll l,r,i,j;
  cin >> l >> r;
  if(r-l>=2019){
    cout << 0 << endl;
    return 0;
  }
  ll ans=2000000000;
  for(i=l;i<=r;i++){
    for(j=i+1;j<=r;j++){
      ans=min(ans,i*j%2019);
    }
  }
  cout << ans << endl;
  return 0;
}