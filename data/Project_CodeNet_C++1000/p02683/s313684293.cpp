#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

vector<ll> C;
vector<vector<ll>> A;
int N,M; ll X; 
ll MAX = 1000000000000000000;
ll min_val = MAX;

void solve(string S){
  if(S.size() < N){
    solve(S+"0");
    solve(S+"1");
    return;
  } 

  ll cost = 0;
  vector<ll> a(M,0);
  for(int i = 0; i < N; i++){
    if(S[i] == '1'){
      cost += C[i];

      for(int j = 0; j < M; j++){
        a[j] += A[i][j];
      }
    }
  }

  for(int j = 0; j < M; j++){
    if(a[j] < X) return;
  }

  min_val = min(min_val, cost);

  return;

}

int main(){
  cout << setprecision(10);
  cin >> N >> M >> X;

  C.assign(N,0);
  A.assign(N, vector<ll>(M,0));

  for(int i = 0; i < N; i++){
    cin >> C[i];
    for(int j = 0; j < M; j++){
      cin >> A[i][j];
    }
  }

  solve("");
  cout << (min_val == MAX ? -1 : min_val) << endl;
}
