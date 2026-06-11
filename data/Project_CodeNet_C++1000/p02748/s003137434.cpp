#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int MIN(vector<int> Vec){//配列の最小値
  int n=Vec.size();
  int min= 2147483647;
  for(int i=0;i<n;i++){
    if(min>Vec.at(i))min=Vec.at(i);
  }
  return min;}
int main() {
  int a,b,m,mi=INT_MAX;
  cin>>a>>b>>m;
  veci p(a);
  veci q(b);
  {rep(i,a)cin>>p[i];}
  {rep(i,b)cin>>q[i];}
  rep(i,m){
    int x,y,c;
    cin>>x>>y>>c;
    x--;y--;
    c*=-1;
    c+=p[x];
    c+=q[y];
    mi=min(c,mi);
  }
  mi=min(mi,(MIN(p)+MIN(q)));
  cout<<mi<<endl;
}