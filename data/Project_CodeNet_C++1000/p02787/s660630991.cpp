#include <bits/stdc++.h>
#define rep(i,e,n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int inf=1000000007;


int main(){
  int n,h;
  cin >> h >> n;
  vector<int> hp(h+1,inf);
  vector<int> attack(n);
  vector<int> mahou(n);
  rep(i,0,n) cin >> attack[i] >> mahou[i];

  hp[0]=0;

  rep(i,1,h+1){
    rep(j,0,n){
      if(attack[j]>=i) hp[i]=min(mahou[j],hp[i]);
      else hp[i]=min(hp[i-attack[j]]+mahou[j],hp[i]);
    }
  }
  cout << hp[h] << endl;
  return 0;
}