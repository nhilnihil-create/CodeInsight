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
  int n; cin >> n;
  unordered_map<string,int> str;
  ll ans  = 0;

  rep(i,n){
    string s; cin >> s;
    sort(all(s));
    if(str.count(s)){
      ans += str[s];
      str[s]++;
    }else{
      str[s]=1;
    }
  }

  cout << ans << endl;

}
