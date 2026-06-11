/************************************/
/* NoobM							*/
/* File Name : cha.cpp				*/
/* Date : 13.07.2020 02:20:47 +06	*/
/************************************/

#include <bits/stdc++.h>

#define rr(i, b)    for (int i = 0; i < int(b); i++)
#define vi(n, a) vector <int> a(n); rr(i, n) cin >> a[i]
#define pvec(a) rr(i, a.size()) cout << a[i] << " "; cout << endl
#define bug(x) cout << #x << " " << x << endl
#define ll long long
#define vii vector <int>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	
	int num = 1;
	int s = n;
	if(k == 1) cout << 0 << endl;
	else if(n >= k) cout << 1 << endl;
	else {
	for(int i = 2; ;i++) {
		s--;
		if(s + n >= k) {
			
			cout << i << endl;
			break;
		}
		s += n;
	}
}
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	
	int t = 1;
	//cin >> t;
	
	while (t--) {
		solve();
	}
    return 0;
}
