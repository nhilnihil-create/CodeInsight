#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  string s; cin >> s;

  string S = "";
  int ans =0;
  int now =0;

  rep(i,s.size()){
    string ss = s.substr(now,i-now+1);
    if(S != ss){
      S = ss;
      ans++;
      now = i+1;
    }
  }
  cout << ans << endl;
}
