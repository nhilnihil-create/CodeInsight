/*
* @Author: Kabid
* @Date:   {{create_time}}
* @Last Modified by:   Kabid
* @Last Modified time: 2020-09-21 11:25:16
*/
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define ll long long
#define  in(x) scanf("%d",&x);
#define out(x) printf("%d",x);
#define  ins(x)  scanf("%s",x);
#define outs(x) printf("%s",x);
#define lin puts("");
#define _ putchar(' ');

int t;       //test cases
ll i, j;	 //iterators
ll n, k ,  q,  d, m, c, c1, c2, d1, x; //variables;
ll mx1 = LLONG_MIN, mx2 = LLONG_MIN, mx = LLONG_MIN, mn = LLONG_MAX;		// max min
char s[6], s1, s2;		// string
ll a [1000001], b [200001] ;
bool mox [1000001];	// array
map <int, int > mp;
vector <vector<ll>> vc;
vector <ll> v;
set <ll> st;
bool r;
ll p = 1000000007;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cin >> t; q = t;
	t = 1;

	while (t--) {

		cin >> n;
		a[0] = 1; a[1] = 0; a[2] = 0; a[3] = 1;
		for (i = 4; i <= n; i++) {
			c = 0;
			for (j = 3; j <= i; j++) {
				c = (c + a[i - j]) % p;
			}
			a[i] = c;
		}
		cout << a[n] << endl;
	}
	return 0;

}