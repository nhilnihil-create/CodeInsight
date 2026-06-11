#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second

const int maxn = 100010;
#define all(x) x.begin(),x.end()

#define ld long double

int n;

int main() {
	cin >> n;
	
	ld sum = 0;
	for (int i =0;i<n;i++) {
		ld x; cin >> x;
		sum += ((ld) 1 / x);
	}
	cout << setprecision(10) <<  (1 / sum);
	
}

