#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

ll pow(ll x,ll y){
  if(y == 0){
    return 1;
  }
  if(y == 1){
    return x;
  }
  if(y%2 == 0){
    return pow(x,y/2)*pow(x,y/2);
  }
  else{
    return x*pow(x,y/2)*pow(x,y/2);
  }
}

int main(){
    ll x;
    cin >> x;
    for(ll i=0; i<=1000; i++){
        for(ll j=-1000; j<=1000; j++){
            if(pow(i,5)-pow(j,5) == x){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}
    