#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define dd pair<double, double>
#define pb(i) push_back(i)
const double PI = 3.14159265359;
const int inf = 1e9+77;
const ll mod = 1e9+7;
const double eps = 1e-7;
//int dir1[8] = {0, 0, 1, -1, 1, -1, 1, -1};
//int dir2[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dir1[4] = {0, 0, 1, -1};
int dir2[4] = {1, -1, 0, 0};

const int N = 1e6;

int main()
{
	int i, j, k;

	bool isprime[N];
	memset(isprime, 0, sizeof(isprime));
	isprime[0] = isprime[1] = true;
	for(i = 2; i < N; i++)
		if(!isprime[i])
			for(j = i+i; j < N; j += i)
				isprime[j] = true;
	
	vector<int> prime;
	for(i = 2; i < N; i++)
		if(!isprime[i])
			prime.pb(i);

	int x; cin >> x;
	cout << (*(lower_bound(prime.begin(), prime.end(), x))) << '\n';
}
