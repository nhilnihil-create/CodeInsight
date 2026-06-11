#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

ll nPr(ll n, ll r){
  ll ret = 1;
  while(r--){
    ret *= n;
    ret %= MOD;
    n--;
  }
  return ret;
}

int main(){
  cout << setprecision(10);
  int N;
  ll K;
  cin >> N >> K;

  vector<vector<int>> v(N);
  for(int i = 0; i < N-1; i++){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--; tmp2--;
    v[tmp2].push_back(tmp1);
    v[tmp1].push_back(tmp2);
  }

  ll ans = K;
  queue<int> q;
  q.push(0);
  vector<int> flg(N, 0);
  flg[0] = 1;

  while(!q.empty()){
    int now = q.front();
    q.pop();
    int degree = 0;
    for(auto next: v[now]){
      if(flg[next] == 0){
        degree++;
        flg[next] = 1;
        q.push(next);
      }
    }
    if(now == 0){
      ans *= nPr(K-1, degree);
    } else {
      ans *= nPr(K-2, degree);
    }
    ans %= MOD;
  }

  cout << ans << endl;
}
