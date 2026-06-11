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
  ll n,ans = 1;
  string s;
  cin >> n >> s;

  char tmp = s.at(0);

  for(int i=1;i<n;i++){
    if(s.at(i)!=tmp){
      ans++;
      tmp = s.at(i);
    }
  }


  cout << ans << endl;
}
