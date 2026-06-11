#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n; cin >> n;
  vector<P> task(n);
  rep(i,n)  cin >> task[i].second >> task[i].first;
  
  sort(task.begin(),task.end());
  
  ll time = 0;
  rep(i,n){
    time += task[i].second;
    if(time>task[i].first){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
}