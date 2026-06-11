#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,k;
  cin >> n >> k;
  int a[n];
  rep(i,n)cin >> a[i];
  int o=0;
  rep(i,n)o+=a[i];
  int ans=0;
  int v[n];
  rep(i,100000){
    if(i==0)continue;
    if(o%i!=0)continue;
    int u=i;
    rep(i,n)v[i]=a[i]%u;
    sort(v,v+n);
    int m=0;
    rep(i,n)m+=v[i];
    int c=m;
    rep(i,c/u)m-=v[n-1-i];
    if(m<=k)ans=max(ans,u);
    u=o/i;
    rep(i,n)v[i]=a[i]%u;
    sort(v,v+n);
    m=0;
    rep(i,n)m+=v[i];
    //cout << m << " " << u << " " << m/u << endl;
    int b=m;
    rep(i,b/u){
      m-=v[n-1-i];
      //if(u==40000)cout << i << " " << m << endl;
    }
    if(m<=k)ans=max(ans,u);
    //if(u==40000)cout << m << endl;
  }
  cout << ans << endl;
}
