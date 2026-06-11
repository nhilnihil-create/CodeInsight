#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long gcd(long long a,long long b) {
  if(b == 0) return a;
  return gcd(b,a%b);
}

struct Sieve {

  int n;
  //f:f[i]がiを最初に割った素数を表す配列 例）f[36] = 2;
  //primes:n以下の素数を集めた配列
  vector<int> f,primes;
  Sieve(int n = 1):n(n),f(n+1) {
    f[0] = f[1] = -1;
    for(int i = 2;i <= n;i++) {
      if(f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for(int j = i*2;j <= n;j += i) if(!f[j]) f[j] = i;
    }
  }
  //xが素数か判定する関数
  bool ifPrime(int x) {
    return f[x] == x;
  }
};

int main() {

  int N;
  cin >> N;

  vector<int> A(N);
  for(int i = 0;i < N;i++) cin >> A[i];

  int g = A[0];
  for(int i = 0;i < N;i++) g = gcd(g,A[i]);

  if(g != 1) cout << "not coprime" << endl;
  else {

    Sieve S(1e6);
    vector<bool> judge(1e6+10,false);
    for(int i = 0;i < N;i++) {
      int a = A[i];
      while(a != 1) {
        if(judge[a]) {
          cout << "setwise coprime" << endl;
          return 0;
        }

        judge[a] = true;
        a = a / S.f[a];
      }

    }

    cout << "pairwise coprime" << endl;

  }


}
