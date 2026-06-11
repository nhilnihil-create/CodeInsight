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
  int N;
  ll K;
  cin >> N >>K;
  vector <ll> A(N);
  vector <ll> F(N);
  rep(i, N)cin >> A[i];
  rep(i, N)cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<ll>());
  ll cons = 0;
  ll r = 1000000000000;
  ll l = -1;
  while (r-l != 1){
    ll nex = (r + l)/2;
    ll temp = 0;
    rep(i, N){
      temp += max(A[i]-nex/F[i], cons);
    }
    if (K < temp) l = nex;
    else r = nex;
  }
  cout << r <<endl;
}
