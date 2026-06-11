#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<complex>
using namespace std;

#define rep(i,n) for(long long i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;

const ll INF = ll(1e18) + 1;
const int intINF = 1e9 * 2 + 3;
//--------------------------------------------------
ulli powN(ulli num,ulli i) {
	return (i > 1) ? num : powN(num * 9, i - 1);
}

ulli gcd(ulli a, ulli b) {return (b <= 0) ? a : gcd(b, a % b);}
ulli lcm(ulli a, ulli b) {return a * b / gcd(a, b);}

bool isPrime(int n)
{
	if (n <= 3)return n > 1;
	if (n % 2 == 0)return false;
	if (n % 3 == 0)return false;
	for (int i = 5; i * i < n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) { return false; }
	}
	return true;
}
//---------------------------------------------------


ulli func(int num) {
	if (num < 2) {
		return 1;
	}
	else if (num >= 2) {
		return num * func(num - 2);
	}
}

void Main()
{
	char n[4];
	rep(i, 3) {
		cin >> n[i];
	}
	rep(i, 3) {
		if (n[i] == '7') {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Main();
	
	return 0;
}