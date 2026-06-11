#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define INF (2000000000)
#define MOD (1000000007)
using namespace std;

typedef vector<int> VI;
typedef vector<int>::iterator VII;
typedef vector<double> VD;
typedef vector<double>::iterator VDI;
typedef pair<int, int> P;


int prime[300000];

int main()
{
	for (int i = 2; i < 300000; i++){
		prime[i] = 1;
	}
	for (int i = 2; i * i < 300000; i++){
		for (int j = i * i; j < 300000; j += i){
			prime[j] = 0;
		}
	}
	for (int i = 1; i < 300000; i++){
		prime[i] += prime[i - 1];
	}
	
	int n;
	while (scanf("%d", &n), n){
		printf("%d\n", prime[n * 2] - prime[n]);
	}
	
	return 0;
}