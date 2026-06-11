#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ii = pair<int, int>;
using ll = long long;

int32_t main(){
	ios::sync_with_stdio(0);	
	int n, r;
	cin >> n >> r;
	if(n>=10)
		cout << r << endl;
	else
		cout << max(0, int(r+(100*(10-n)))) << endl;
}
