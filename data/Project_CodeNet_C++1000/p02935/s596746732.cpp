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
vector <ld> v;

int main() {
	cin >> n;
	for (int i =0;i<n;i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	ld cur = (v[0] + v[1]) / 2;
	for (int i =2;i<n;i++) {
		cur = (cur + v[i]) / (ld) 2;
	}
	cout << setprecision(10) << cur;
}

