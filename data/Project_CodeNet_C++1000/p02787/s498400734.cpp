#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()


int main(){
  int H, N; cin >> H >> N;
  vector <P> AB(N);
  rep(i, N){
    int a, b;cin >> a >> b;
    AB[i] = make_pair(a, b);
  }
  int inf = 1000000000;
  int dp[H + 1];
  rep(i, H + 1) dp[i] = inf;
  dp[0] = 0;
  rep(i, H){
    rep(j, N){
      dp[min(i + AB[j].first, H)] = min(dp[min(i + AB[j].first, H)], dp[i] + AB[j].second);
    }
  }
  cout << dp[H] << endl;
}

