#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

void to_sieve(vector<bool>& sieve, vector<int>& num, int N)
{
  int sum = 0, prev;
  for (int i = 0; i < N; i++){
    if (sieve[num[i]] == true){
      if (num[i] == prev){
	sum--;
	prev = 0;
      }
      continue;
    }
    sum++;
    int temp = num[i];
    while (temp < MAX){
      sieve[temp] = true;
      temp += num[i];
    }
    prev = num[i];
  }
  cout << sum << '\n';
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  vector<bool> sieve(MAX, false);
  cin >> N;
  vector<int> num(N);
  for (int i = 0; i < N; i++)
    cin >> num[i];
  sort(num.begin(), num.end());
  to_sieve(sieve, num, N);
  return 0;
}
