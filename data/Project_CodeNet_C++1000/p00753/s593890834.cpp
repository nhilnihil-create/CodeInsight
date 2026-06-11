#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

int n;
bool is_prime[1000000];

int main(){
	fill(is_prime, is_prime + 1000000, 1);
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= 2 * 123456; i++){
		if (is_prime[i]){
			for (int j = i * 2; j <= 2 * 123456; j += i){
				is_prime[j] = 0;
			}
		}
	}

	while (cin >> n&&n){
		int co = 0;
		FOR(i, n + 1, 2 * n + 1){
			if (is_prime[i])co++;
		}
		cout << co << endl;
	}
}