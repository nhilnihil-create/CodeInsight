#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,k,c;
  cin >> n >> k >> c;
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  string s;
  cin >> s;
  vector<pair<int,int>> p(n);
  vector<pair<int,int>> q(n);
  if(s[0]=='o')p[0]=make_pair(1,0);
  else p[0]=make_pair(0,c);
  if(s[n-1]=='o')q[n-1]=make_pair(1,0);
  else q[n-1]=make_pair(0,c);
  rep(i,n-1){
    int y=i;
    if(p[y].second>=c&&s[y+1]=='o')p[y+1]=make_pair(p[y].first+1,0);
    else p[y+1]=make_pair(p[y].first,p[y].second+1);
  }
  rep(i,n-1){
    int y=n-1-i;
    if(q[y].second>=c&&s[y-1]=='o')q[y-1]=make_pair(q[y].first+1,0);
    else q[y-1]=make_pair(q[y].first,q[y].second+1);
  }
  //rep(i,n)cout << q[i].first << " " << q[i].second << endl;
  if(q[1].first<k)cout << 1 << endl;
  rep(i,n-2){
    if(p[i].first+q[i+2].first<k)cout << i+2 << endl;
  }
  if(p[n-2].first<k)cout << n << endl;
}
