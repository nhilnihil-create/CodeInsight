#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a,a);
}

int lcm(int x, int y){
	if(x == 0 || y==0) return 0;
	return x/gcd(x, y) *y;
}

signed main(){
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  for( int i = 0; i < N; i++ ){
    cin >> A[i];
    A[i] /= 2;
  }

  int cnt = 0;
  int B = A[0];
  while( B%2 == 0 ){
    B /= 2;
    cnt++;
  }
  for( int i = 1; i < N; i++ ){
    B = A[i];
    int now = 0;
    while( B%2 == 0 ){
      B /= 2;
      now++;
    }
    //2で割れる回数が異なったら
    if( cnt != now ){
      cout << 0 << endl;
      return 0;
    }
  }

  int LCM;
  if( N >= 2 ) LCM = lcm(A[0], A[1]);
  else LCM = A[0];
  
  for( int i = 2; i < N; i++ ){
    LCM = lcm(LCM, A[i]);
    if( LCM > M ){
      cout << 0 << endl;
      return 0;
    }
  }

  cout << (M/LCM+1)/2 << endl;
}
