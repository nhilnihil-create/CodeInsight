#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>

#define rep(i,n)         for(int i=(int)0; i<(int)n; i++)
#define REP(i,m,n)       for(int i=(int)m; i<(int)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define prt(var)         cout << var << endl
#define prtd(n, var)     cout << fixed << setprecision(n) << var << endl
#define prt2(v1, v2)     cout << v1 << " " << v2 << endl
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << endl
#define prtall(var)      rep(i,var.size()){cout << var[i] << " ";} cout << endl

//----------------------------------------------------------------
int n;
void dfs(string s){
  //cout << s << endl;
  if(s.size()>n) return;
  if(s.size()==n){
    cout << s << endl;
    return;
  }
  char mx='a';
  rep(i,s.size()){
    if(s[i]-mx>0) mx=s[i];
  }
  mx++;
  //cout << "mx--> " << mx << endl;
  for(char x='a'; x<=mx; x++){
    string next_s = s + x;
    dfs(next_s);
  }
  return;
}

int main(void) {
  cin >> n;
  dfs("a");
}
