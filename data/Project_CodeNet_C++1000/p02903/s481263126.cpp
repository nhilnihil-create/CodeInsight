#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
*/

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b) * b;
}
ll func2(ll n){
  ll res = 0;
  while(n%2 == 0){
    n /= 2;
    res++;
  }
  return res;
}

ll zyou(ll a,ll b){//a＾b
  ll res = 1;
  for(int i = 1;i<=b;i++){
    res *= a;
  }
  return res;
}
struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t),weight(w){ }
};

typedef pair<int,int> P;
using Graph = vector<vector<Edge>>;

ll calc(ll a, ll b, ll p){//aのb乗をpで割った余り
  if(b == 0) return 1;

  else if(b%2 == 0){
    ll d = calc(a,b/2,p);
    return (d*d)%p;
  }
  else if(b%2 == 1){
    return (a * calc(a,b-1,p))%p;
  }
}



bool is_prime(int n){//nが素数であるかどうか判定 iで割り切れると素数でない
    if(n == 1) return false;//1は例外
    for(int i = 2;i*i <= n;i++){
        if(n%i == 0) return false;
    }
    
    return true;
}
int dfs(int x,int y,int H,int W,vector<vector<char>> &masu){
  if(masu[x][y] == '#'){

  }
}
bool palin(string S){
  int n = S.size();
  bool flag = true;
  if(n%2 == 0){
    for(int i = 0;i<=n/2-1;i++){
      if(S[i] != S[n-i-1]){
        flag = false;
        break;
      }
    }
  }
  else if(n%2 == 1){
    for(int i = 0;i<=n/2-1;i++){
      if(S[i] != S[n-i-1]){
        flag = false;
        break;
      }
    }
  }
  return flag;
}
int main(){
  int H,W,A,B;
  cin >> H >> W >> A >> B;
  vector<vector<int>> masu(H, vector<int>(W));

  for(int i = 0;i<H;i++){
    for(int j = 0;j<W;j++){
      if(i < B){
        if(j < A) masu[i][j] = 1;
        else if(j >= A) masu[i][j] = 0;
      }
      else if(i >= B){
        if(j < A) masu[i][j] = 0;
        else if(j >= A) masu[i][j] = 1;
      }
    }
  }

  for(int i = 0;i<H;i++){
    for(int j = 0;j<W;j++){
      cout << masu[i][j];
      if(j == W-1) cout << endl;
    }
  }
  
}