/************************************/
/* NoobM							*/
/* File Name : chaa.cpp				*/
/* Date : 13.07.2020 02:37:00 +06	*/
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
	vector<vii> a(3, vii (3));
	rr(i, 3) {
		rr(j, 3) cin >> a[i][j];
	}
	
	int n;
	cin >> n;
	
	map<int, bool> is;
	
	rr(i, n) {
		int x;
		cin >> x;
		
		is[x] = true;
	}
	
	rr(i, 3) {
		rr(j, 3) {
			int x = a[i][j];
			if(is[x] == true) a[i][j] = -1;
		}
	}
	int flag = 0;
	
	rr(i, 3) {
		int counter = 0;
		int counter2 = 0;
		rr(j, 3) {
			if(a[i][j] == -1) counter++;
			if(a[j][i] == -1) counter2++;
		}
		if(counter == 3 || counter2 == 3) flag = 1;
	}
	
	int c = 0, c2 = 0;
	
	rr(i, 3) {
		rr(j, 3) {
			if(i == j && a[i][j] == -1)c++;
			if(i + j == 2 && a[i][j] == -1) c2++;
		}
	}
	
	if(c == 3 || c2 == 3) flag = 1;
	
	if(flag == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	
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
