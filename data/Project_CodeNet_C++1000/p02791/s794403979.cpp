#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<string,int>;

int main(){
  ll N;
  cin >> N;
  ll minj = 200000;
  vector<ll>P(N);
  int ans = 0;
  rep(i,N){
    cin >> P[i];
    if(minj >=P[i])ans++;
    minj = min(minj,P[i]);
  }
  cout << ans << endl;
}