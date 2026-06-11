#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

long long int my_power(long long int base, long long int up)
{
  long long int num = 1;
  while (up > 0){
    if (up & 1)
      num = (num * base) % MOD;
    up >>= 1;
    base = (base * base) % MOD;
  }
  return num;
}

void calculate(int& N, int& K)
{
  long long int sum_of_gcd = 0; 
  vector<long long int> num_of_gcd(K + 1);
  for (int i = K; i >= 1; i--){
    num_of_gcd[i] = my_power(K / i, N);
    for (int j = i * 2; j <= K; j += i)
      num_of_gcd[i] = (num_of_gcd[i] - num_of_gcd[j] + MOD) % MOD;
  }
  for (int i = 1; i <= K; i++)
    sum_of_gcd = (sum_of_gcd + i * num_of_gcd[i]) % MOD;
  cout << sum_of_gcd << '\n';
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  calculate(N, K);
  return 0;
}
