#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

ll n;
void DFS(ll p,ll q,string s){
  if(p==n){
    cout << s << endl;
    return;
  }
  for(ll i=0;i<=q+1;i++){
    DFS(p+1,max(i,q),s+char('a'+i));
  }
}
/*文字列の長さ、最大の文字、現在の文字列の三変数でDFSを作る*/
int main() {
  cin >> n;
  DFS(0,-1,"");
}