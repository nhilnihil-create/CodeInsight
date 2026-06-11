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
  ll n,k,s; cin >> n >> k >> s;
  rep(i,n){
    if(i<k) cout << s;
    else {
      if(s==1||s==2) cout << s+1;
      else cout << s-1;
    }
    cout << " " ;
  }
}
