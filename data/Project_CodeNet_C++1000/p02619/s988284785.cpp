// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
signed main(){
  init_io();
  ll d,n=26,score=0;
  cin >> d;
  vector<ll> c(n),contest(d);
  vector<vector<ll>> s(d,vector<ll>(n));
  for(int i=0;i<n;i++){
    cin >> c[i];
  }
  for(int i=0;i<d;i++){
    for(int j=0;j<n;j++){
      cin >> s[i][j];
    }
  }
  for(int i=0;i<d;i++){
    cin >> contest[i];
    contest[i]--;
  }
  for(int i=0;i<d;i++){
    score += s[i][contest[i]];
    for(int j=0;j<n;j++){
      ll day = 0;
      for(int k=i;k>=0;k--){
        if(contest[k]==j){
          day = k+1;
          break;
        }
      }
      score -= (i+1-day)*c[j];
    }
    cout << score << endl;
  }
}
