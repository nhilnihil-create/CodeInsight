#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

ll scores[5500][5500];

int main(){
  int n,k;cin>>n>>k;
  vector<int>p(n);
  rep(i, n){ cin>>p[i];p[i]--; }
  vector<ll>c(n);
  rep(i, n)cin>>c[i];

  vector<int>loopc(n);
  rep(i, n){
    int nex = i;
    rep1(j, n){
      loopc[i]++;
      scores[i][j] = scores[i][j-1] + c[nex];
      nex = p[nex];
      if(i==nex)break;
    }
  }

  ll result = -INF;

  // first loop
  rep(i, n)rep1(j, n){
    if(j>k)continue;
    result = max<ll>(result, scores[i][j]);
  }

  rep(i, n){
    ll lc = loopc[i];
    if(k<=lc)continue;
    ll count = k/lc;

    // one before last one loop
    if(count>=2){
      rep(j, lc+1){
        result = max<ll>(result, scores[i][lc]*(count-1) + scores[i][j]);
      }
    }

    // last one loop
    rep1(j, k%lc){
      result = max<ll>(result, scores[i][lc]*count + scores[i][j]);
    }
  }

  cout<<result<<endl;

  return 0;

rep(i, n)cout<<loopc[i]<<' ';cout<<endl;
rep(i, n){
rep(j, n+1)cout<<scores[i][j]<<' ';cout<<endl;
}

  return 0;
}


