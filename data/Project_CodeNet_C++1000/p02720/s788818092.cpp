#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
  int k;
  cin >> k;
  queue<ll> q;
  rep(i,9) q.push(i+1);
  rep(i,k-1){
    ll x = q.front();
    q.pop();
    if(x%10 != 0) q.push(x*10 + x%10 -1);
    q.push(x*10 + x%10);
    if(x%10 != 9) q.push(x*10 + x%10 +1);
  }
  cout << q.front() << endl;
}
