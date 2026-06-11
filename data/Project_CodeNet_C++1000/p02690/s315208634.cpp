#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)


int main(){
  ll X;
  cin >> X;
  for(ll i=0;i<=120;i++){
    ll a = i*i*i*i*i;
    for(ll j=-120;j<=120;j++){
      ll b = j*j*j*j*j;
      if(a-b==X){
        cout << i << " " << j << endl;
        return 0;
      }
    }
    
  }
}
