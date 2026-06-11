#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 10000000000000000
#define ll long long

using namespace std;



int main(){
  ll n,q;
  cin >> n >> q;
  ll i = n;
  for(ll k = 0; k < 5; k++){
    i |= (i >> (1 << k));
  }
  i++;

  ll tree[i+1];

  for(ll k = 0; k <= i; k++){
    tree[k] = 0;
  }
  
  for(ll k = 0; k < q; k++){
    ll com,x,y;
    cin >> com >> x >> y;
    if(com == 0){
      while(x <= i){
	tree[x] += y;
	x += (x & -x);
      }
    }else{
      ll ret = 0;
      x--;
      while(x){
	ret += tree[x];
	x -= (x & -x);
      }

      while(y){
	ret -= tree[y];
	y -= (y & -y);
      }
      cout << -ret << endl;
    }

  }

}