#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N,M;
  cin >> N >> M;
  ll p[M];
  string S[M];
  for(int i=0;i<M;i++){
    cin >> p[i] >> S[i];
  }
  ll err = 0;
  ll ans = 0;
  bool ok[N+1];
  ll W[N+1];
  for(int i=1;i<N+1;i++){
    ok[i]=false;
    W[i]=0;
  }
  for(int j=0;j<M;j++){
    if(ok[p[j]]) continue;
    if(S[j]=="AC"){
      ans++;
      err += W[p[j]];
      ok[p[j]]=true;
    }
    else if(S[j]=="WA") W[p[j]]++;
  }
  cout << ans << " " << err << endl;
}
