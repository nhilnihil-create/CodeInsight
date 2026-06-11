#include <bits/stdc++.h>
using namespace std;

#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {cout << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}

ll pow(ll x, ll y) {
	if(y == 0)
	return 1;
	ll temp = pow(x, y/2);
	temp = (temp*temp);
	if(y%2 == 1)
		temp *= x;
	return temp;
}

#define int ll

int32_t main() {
	int k, q;
	cin >> k >> q;
	int d[k];
	for(int i = 0; i < k; i++)
		cin >> d[i];
	while(q--) {
		int n, x, m;
		cin >> n >> x >> m;
		vi td(k);
		for(int i = 0; i < k; i++)
			td[i] = d[i]%m;
		int z = 0;
		for(int i = 0; i < k; i++)
			if(d[i]%m == 0)
				z++;
		z *= (n - 1)/k;
		for(int i = 0; i < (n - 1)%k; i++)
			if(d[i]%m == 0)
				z++;
		//error(z);
		int T = 0;
		for(int xx : td)
			T += xx;
		int lst = ((n - 1)/k)*T + x;
		for(int i = 0; i < (n - 1)%k; i++)
			lst += td[i];
		//error(lst);
		z += lst/m - x/m;
		//error(z);
		cout << n - 1 - z << '\n'; 
	}
}