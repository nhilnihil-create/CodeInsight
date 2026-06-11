#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s,t;
    cin >> s>>t;
    int ans=0;
    REP(i,s.length()){
        if(s[i]==t[i]) continue;
        ans++;
    }
    cout<<ans<<endl;
  
  return 0;
}
