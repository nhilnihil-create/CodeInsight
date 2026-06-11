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
ll n;
signed main(){
  init_io();
  cin >> n;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      ll dist = abs(i-j);
      for(int k=0;;k++){
        if(dist&(1ll<<k)){
          cout << k+1 << " ";
          break;
        }
      }
    }
    cout << endl;
  }
}
