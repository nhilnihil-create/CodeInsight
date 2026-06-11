#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define len(x) int((x).size())
#define res(x) cout << ((x) ? "YES\n" : "NO\n" )

typedef long long int integer;
typedef long double doble;

void solution() {
	int n;
	cin >> n;
	vector<int> a(n), b;
	for(int& x:a) {
		cin >> x;
		b.push_back(x);
	}
	sort(all(b));
	for(int& x:a) {
		cout << (x == b[n-1] ? b[n-2] : b[n-1]);
		cout << endl;
	}
}
 
int main(){
	int t = 1;
	//cin >> t;
	while(t--) solution();
	return 0;
}