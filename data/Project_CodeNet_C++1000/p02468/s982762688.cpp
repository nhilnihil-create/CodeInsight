// Numeric

// 整数論

#include<vector>
#include<set>

// 素因数分解：力任せ
std::vector<int> prime_factor(const int n) {
  int tmp = n;
  std::vector<int> result;
  for(int i = 2; i * i <= n; ++i) {
    while(!(tmp % i)) {
      tmp /= i;
      result.push_back(i);
    }
  }
  if(tmp != 1) result.push_back(tmp);
  return result;
}

// 素数判定表：Sieve of Eratosthenes
std::vector<bool> Eratosthenes(const int n) {
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; is_prime[i] && i * i <= n; ++i)
    for(int j = i * i; j <= n; j += i)
      is_prime[j] = false;
  return is_prime;
}

// べき乗：繰り返し二乗法/二進累乗アルゴリズム
int power(const int m, const int n) {
  if(!n) return 1;
  if(n & 1) return power(m * m, n >> 1) * m;
  return power(m * m, n >> 1);
}

int mod_power(const long long int m, const long long int n, const int mod) {
  if(!n) return 1;
  if(n & 1) return mod_power(m * m % mod, n >> 1, mod) * m % mod;
  return mod_power(m * m % mod, n >> 1, mod) % mod;
}

// 乗算
int mod_multiply(const long long int m, const long long int n, const int mod) {
  if(!n) return 0;
  if(n & 1) return (m + mod_multiply((m << 1) % mod, n >> 1, mod)) % mod;
  return mod_multiply((m << 1) % mod, n >> 1, mod);
}

int mod_multiply(std::vector<long long int> n, const int mod) {
  if(n.size() == 1) return 1;
  return mod_multiply(std::vector<long long int>(n.begin() + 1, n.end()), mod);
}

// 最大公約数：Euclidean algorithm
int gcd(const int m, const int n) {
  return n ? gcd(n, m % n) : m;
}

// 最小公倍数
int lcm(const long long int m, const long long int n) {
  return m * n / gcd(m, n);
}

// m x + n y = gcd(m, n) であるような x, y, gcd を求める：Extended Euclidean algorithm
struct ExtendedGCD {int x, y, gcd;};
ExtendedGCD extended_gcd(const int m, const int n, const int x = 1, const int xx = 0, const int y = 0, const int yy = 1) {
  if(!n) return {x, y, m};
  return extended_gcd(n, m % n, xx, x - m / n * xx, yy, y - m / n * yy);
}

// 自然数 n と互いに素な n 以下の自然数の個数：Euler's totient function
int phi(const int n) {
  int answer = n;
  auto list = prime_factor(n);
  for(auto i: std::set<int>(list.begin(), list.end())) answer -= answer / i;
  return answer;
}

////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << mod_power(a, b, 1000000007) << endl;
}