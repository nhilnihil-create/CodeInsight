#include <iostream>
#include <cstring>
#define MAX_N 2246912

using namespace std;

int N, num_prime[MAX_N + 1];
bool is_prime[MAX_N + 1];

void Init()
{
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0] = is_prime[1] = false;
  int cnt = 0;
  for (int i = 2; i <= MAX_N; i++) {
    if (is_prime[i]) {
      cnt++;
      for (int j = i * 2; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }

    num_prime[i] = cnt;
  }
}

int main()
{

  Init();

  while (cin >> N && N) {
    cout << num_prime[2 * N] - num_prime[N] << endl;
  }

}