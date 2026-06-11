#include <bits/stdc++.h>
using namespace std;


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

// 円周率
// M_PI

// #include <iomanip> // setprecisionを使用するのに必要
// cout << std::fixed << std::setprecision(15) << y << endl;

// 昇順
// priority_queue<int, vector<int>, greater<int> > queue;
  int *a;
  int *b;
  int *c;
  int *d;
int q;
int64_t find(int val[],int index,int n,int m){
  if(index==n){
    int64_t score = 0;
    for(int i=0;i<q;i++){
      if(val[b[i]-1]-val[a[i]-1] == c[i]) score += d[i];
    }
    return score;
  }

  int64_t score = 0;
  int64_t scoreMax = 0;
  for(int i=val[index-1];i<=m;i++){
    val[index] = i;
    score = find(val,index+1,n,m);
    if(scoreMax<score)scoreMax = score;
  }
  return scoreMax;
}

signed main() {
  int n,m;
  cin >> n >> m >> q;
  
  a = new int[q];
  b = new int[q];
  c = new int[q];
  d = new int[q];

  
  for(int i=0;i<q;i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  
  int val[n] = {0};
  val[0] = 1;
  
  cout << find(val, 1, n, m) << endl;

  delete[] a;
  delete[] b;
  delete[] c;
  delete[] d;


  
  //  1 1 1 1 ... 1
  //  1 2 2 4 ... 5
  //  1 3 3 5 ... 5
  //  1 4 4
  //  1 5 5
  
  
  
  
  
  
  return 0;
}