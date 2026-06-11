#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define gap ' '
#define L(i) ((i) - (&i))
#define mp make_pair
#define debug puts("WHAP")

const int MAXN = 100;
const int MAX = 1e5;
const int mxn = 1e5;
const int MOD = 1e9+7;
const int INF = 1e9;
const int N = 50;

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = n-1; i > 0; --i){
		if(a[i] < a[i-1])
			a[i-1]--;
	}	
	for(int i = 0; i < n-1; ++i)
		if(a[i] > a[i+1]){
			cout << "No" << "\n";
			return 0;
		}
	cout << "Yes" << "\n";
	return 0;
}
