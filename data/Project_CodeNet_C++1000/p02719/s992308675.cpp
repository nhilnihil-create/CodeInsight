
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(int argc, char* argv[]) {

	ll n, k;
	cin >> n >> k;

	ll m = n % k;
	m = min(m, abs(m - k));
	cout << m << endl;
}