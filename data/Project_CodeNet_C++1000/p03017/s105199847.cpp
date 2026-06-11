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
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;

  string s,res;
  cin >> s;

  ll m=max(c,d);

  int x=0;
  for(ll i=a;i<m;i++){
    if(s.at(i)=='#' && x){
      res="No";
      cout << res << endl;
      return 0;
    }

    if(s.at(i)=='#'){
      x=1;
    }
    else{
      x=0;
    }
  }

if(c<d){
  res="Yes";
  cout << res << endl;
}

else{
  for(ll i=b-1;i<d;i++){
    if(s.at(i-1)=='.' &&
       s.at(i)=='.' &&
       s.at(i+1)=='.'){
           res="Yes";
           cout << res << endl;
           return 0;
         }
   }

  res="No";
  cout << res << endl;
}


return 0;

  }