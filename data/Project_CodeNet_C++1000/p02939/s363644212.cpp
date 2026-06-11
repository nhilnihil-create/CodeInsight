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
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  string s;
  ll cnt=0;
  cin >> s;
  ll n = s.size();
  char prev='0';
  for(int i=0;i<n;){
    cnt++;
    if(s[i]!=prev){
      prev = s[i];
      i++;
    }else{
      if(i==n-1){
        cnt--;
      }
      i+=2;
      prev = '0';
    }
  }
  cout << cnt << endl;
}
