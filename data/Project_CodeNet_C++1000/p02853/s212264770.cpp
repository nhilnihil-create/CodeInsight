#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int x; cin >> x;
  int y; cin >> y;
  int prise[3]={300000,200000,100000};
  int ans=0;
  if(x < 4) ans+=prise[x-1];
  if(y < 4) ans+=prise[y-1];
  if((x==1)&&(y==1)){
    ans +=400000;
  }
  cout << ans << endl;
  return 0;
}


