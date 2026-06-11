#include <iostream>
#include <cmath>

using namespace std;

int find_diversor_num(long long int num)
{
  int count = (num > 1)? 1 : 0;
  int num_sqrt = sqrt(num);
  for (int i = 2; i <= num_sqrt; i++)
    if (num % i == 0)
      count = (num / i == i)? count + 1 : count + 2;  
  return count;
}

int find_mod_one(long long int num)
{
  int count = 1;
  int num_sqrt = sqrt(num);
  for (int i = 2; i <= num_sqrt; i++)
    if (num % i == 0){
      long long int temp = num, a = i, b = num / i;
      while (temp % a == 0)
	temp /= a;
      if (temp % a == 1)
	count++;
      if (a != b){
	temp = num;
	while (temp % b == 0)
	  temp /= b;
	if (temp % b == 1)
	  count++;
      }
    }
  return count;
}

void calculate(long long int& N)
{
  cout << find_diversor_num(N - 1) + find_mod_one(N) << '\n';
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int N;
  cin >> N;
  calculate(N);
  return 0;
}
