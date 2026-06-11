#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

ll calc(ll h){
  if(h==1) return 1;
  else return 1+2*calc(h/2);
}
 
int main(){
  ll h;
  cin >> h;
  ll ans = calc(h);
  cout << ans << endl;
  return 0;
}
