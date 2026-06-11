#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll a,b,k; cin >> a >> b >> k;

  if(a>=k) a-=k;
  else{
    b-=k-a;
    a=0;
  }

  if(b<0) b=0;
  
  cout << a << " " << b << endl;
  
  return 0;
}
