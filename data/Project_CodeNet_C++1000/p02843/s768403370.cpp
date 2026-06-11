#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll x;
  cin >> x;

  ll sum=0,a,b,c;
  a=x%100;
  for(ll i=5;i;i--){
    b=a;
    a=a%i;
    c=b/i;
    sum+=c*100;
  }

  if(sum>x){
    cout << 0 << endl;
    return 0;
  }

  cout << 1 << endl;

}
