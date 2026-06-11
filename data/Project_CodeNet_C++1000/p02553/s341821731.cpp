/*
* @Author: Kabid
* @Date:   {{create_time}}
* @Last Modified by:   Kabid
* @Last Modified time: 2020-09-19 12:16:37
*/
#include<bits/stdc++.h>
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
ll n, k , p, q,  d, m, c, c1, c2, d1; //variables;
ll mx = LLONG_MIN, mn = LLONG_MAX;		// max min
string s, s1, s2;		// string
ll a [1000001], b [200001] , mox [200001];	// array
map <int, int > mp;
vector <vector<ll>> vc;
vector <ll> v;
set <ll> st;
bool r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cin >> t; q=t;
	t = 1;
	while (t--) {


		cin >> p >> q >> d >> m;
		mx = max(mx, p * d);
		mx = max(mx, p * m);
		mx = max(mx, q * d);
		mx = max(mx, q * m);
		cout << mx << endl;
	}


	return 0;

}
