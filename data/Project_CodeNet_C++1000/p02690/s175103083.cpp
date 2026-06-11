#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  ll x;
  cin >> x;
  ll a,b;
  for(ll i=-1000; i<=1000; i++){
    ll cnt = x+i*i*i*i*i;
    if(cnt==0){
      a = 0;
      b = i;
      break;
    }
    if(cnt>0){
      for(ll j=1; j<=1000; j++){
        if(cnt-j*j*j*j*j==0){
          a = j;
          b = i;
          break;
        }
      }
    }else{
      for(ll j=-1000; j<0; j++){
        if(cnt-j*j*j*j*j==0){
          a = j;
          b = i;
          break;
        }
      }
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
