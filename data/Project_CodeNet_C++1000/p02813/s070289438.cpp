#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;
int main(){
  int n;cin >> n;
  vector<int> p(n),q(n),base(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];
  rep(i,n)base[i] = i+1;
  int a = 1,b = 1;
  int aans,bans;
  do{
    // rep(i,n) printf("%d ",base[i]);
    // cout << endl;
    // printf("%d %d\n",a,b);
    bool pflag = true;
    bool qflag = true;
    rep(i,n) if(base[i]!=p[i]) pflag = false;
    rep(i,n) if(base[i]!=q[i]) qflag = false;
    if(!pflag) a++;
    else aans = a;
    if(!qflag) b++;
    else bans = b;
  }while(next_permutation(base.begin(),base.end()));
  cout << abs(aans-bans) << endl;
}