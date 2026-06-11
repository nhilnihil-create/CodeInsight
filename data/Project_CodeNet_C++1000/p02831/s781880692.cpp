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

  ll a,b,c,d,i;
  cin >> a >> b ;

  c=max(a,b);
  d=min(a,b);
  for(i=c;i<=a*b;i+=c){
    if(i%a==0 && i%b==0){
      cout << i << endl;
      return 0;
    }
  }

  cout << a*b << endl;

}
