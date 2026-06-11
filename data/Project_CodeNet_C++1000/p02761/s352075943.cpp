#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  vector<int> s(m);
  vector<char> c(m);
  rep(i,m){
    cin>>s[i]>>c[i];
    s[i]--;
  }
      rep(i,1000){
        bool ans=true;
        string a=to_string(i);
        int keta=a.size();
        if(keta!=n)continue;
        rep(j,m)if(a[s[j]]!=c[j])ans=false;
        if(ans){
          cout<<i<<endl;
          return 0;
        }
      }
  cout<<-1<<endl;
}