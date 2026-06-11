#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<string.h>
#include<functional>
#include<set>
using namespace std;

#define INF 1<<21
#define DIV 1000000007
#define MAX 250000



int main(){
  char prime[MAX];
  prime[0] = 0;
  prime[1] = 0;
  memset(prime, 1, sizeof(prime));
  for (int i = 2; i*i <MAX ; i++) {
	if (prime[i]) {
	  for (int j = 2*i; j < MAX; j += i) {
		prime[j] = 0;
	  }
	}
  }
  int n;
  while (cin >> n, n) {
	int cnt = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
	  if (prime[i])cnt++;
	}
	cout << cnt << endl;
  }
  return 0;
}