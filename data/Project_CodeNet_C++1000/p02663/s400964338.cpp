#include <bits/stdc++.h>
using namespace std;

constexpr int64_t INF = 1'010'000'000'000'000'017LL;
constexpr int64_t MOD = 1'000'000'007LL;
constexpr double EPS = 1e-12;
constexpr double PI = 3.14159265358979323846;

#define FOR(i, start, end) for(uint64_t i=start; i<end; i++)
#define REP(i, n) FOR(i, 0, n)

// 最大公約数gcd
// 最小公倍数lcm=m*n/gcd
uint64_t gcd(uint64_t m, uint64_t n) {
  uint64_t temp;
  while (m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}

uint64_t lcm(uint64_t m, uint64_t n) {
  return (m*n)/gcd(m,n);
}

void comb(vector<vector <uint64_t> > &v){
  for(uint64_t i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(uint64_t k = 1;k <v.size();k++){
    for(uint64_t j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

// 掛け算オーバーフロー判定
bool is_product_overflow(uint64_t a, uint64_t b) {

	uint64_t prod = a * b;
	
	return (prod / b != a);
}

//素因数分解
void primeFactorization(uint64_t a, list<uint64_t> &factors){ //素因数分解を出力するプログラム
  long i,sq;
  if(a%2==0){ //偶数の場合
    factors.push_back(2);
    primeFactorization(a/2,factors); //2で割った値で再帰
    return;
  }
  sq = sqrt(a);
  for(i=3;i<=sq;i+=2){ //3以上√a以下の奇数の場合
	if(a%i==0){
	  factors.push_back(i);
      primeFactorization(a/i,factors); //割れた値で再帰
      return;
	}
  }
  //偶数でも3以上√a以下の奇数の場合でも割り切れない場合
  if(a!=1){ //aが1でないなら、a自身は素数
    factors.push_back(a);
  }
}

signed main() {
  uint64_t h1,h2,m1,m2,k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  
  uint64_t minuteDiff = m2 - m1 + (h2 - h1)*60;
  
  cout << minuteDiff - k << endl;
  
  return 0;
}