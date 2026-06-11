#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int N,K;
vector<vector<int>> v;

ll nPr(ll n, ll r){
  ll ret = 1;
  for(ll i = 0; i < r; i++){
    ret *= (n - i);
    ret %= MOD;
  }
  return ret;
}

int main(){
  cout << setprecision(10);
  cin >> N >> K;
  v.assign(N, vector<int>());
  for(int i = 0; i < N-1; i++){
    int tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--; tmp2--;
    v.at(tmp1).push_back(tmp2);
    v.at(tmp2).push_back(tmp1);
  }

  ll ans = K;
  map<int,bool> m;
  queue<int> q;
  q.push(0);

  m[0] = true;

  while(!q.empty()){
    int now = q.front();
    q.pop();
    // cerr << "now: " << now << " ans: " << ans << endl; 
    
    // number of child
    ll tmp = 0;
    for(auto next: v.at(now)){
      if(m.count(next) == 0){
        tmp++;
        m[next] = true;
        q.push(next);
      }
    }
    if(tmp != 0){
      if(now == 0){
        ans *= nPr(K-1, tmp);
        ans %= MOD;
      } else { 
        ans *= nPr(K-2, tmp);
        ans %= MOD;
      }
    } 
  }
  cout << ans << endl;
}

