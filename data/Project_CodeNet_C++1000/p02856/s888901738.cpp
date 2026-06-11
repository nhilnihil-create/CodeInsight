#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll m;
  cin >> m;
  ll p=0;
  ll o=-1;
  rep(i,m){
    ll d,c;
    cin >> d >> c;
    o+=c;
    p+=d*c;  
  }
  cout << o+(p-1)/9 << endl;
}
