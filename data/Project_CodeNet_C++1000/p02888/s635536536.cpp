#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const double pi=acos(-1);



//基本的に勝つ手をだす．
//勝つ手がなければ，K回後に勝つ手以外を出す．

int main(){
  int n;
  cin>>n;
  vector<int> l(n);
  rep(i,n){
    cin>>l[i];
  }

  sort(l.begin(),l.end());//小さい順
  ll ans=0;

  for(int i=0; i<n; i++){
  //  cout<<l[i]<<endl;
    for(int j=0;j<i;j++){
      for(int k=0; k<j;k++){
        if(l[k]+l[j]>l[i] && l[j]<l[i]+l[k]){
          ans++;
        }
      }
    }
  }

  cout<<ans<<endl;


}
