#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>
#include <tuple>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll sq(ll num) { return num*num; }
ll mod_pow(ll x, ll n) {
	if (n == 0)return 1;
	if (n == 1)return x%MOD;
	ll res = sq(mod_pow(x, n / 2));
	res %= MOD;
	if (n % 2 == 1) {
		res *= x;
		res %= MOD;
	}
	return res;
}
ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return a*b % MOD; }

int cnt = 0;

void insertion_sort(vector<int> &a,int n,int g){
	FOR(i,g,n){
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v){
			a[j+g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = v;
	}
}

vector<int> make_g(int n){
	vector<int> res;
	int num = 1;
	res.push_back(1);
	while(1){
		num = 3*num+1;
		if(num >= n)break;
		res.push_back(num);
	}
	reverse(ALL(res));
	return res;
}

void shellsort(vector<int> &a,int n){
	vector<int> G = make_g(n);
	rep(i,G.size())insertion_sort(a,a.size(),G[i]);
	cout << G.size() << endl;
	rep(i,G.size()){
		if(i == 0)cout << G[i];
		else cout << " " << G[i];
	}
	cout << endl;
}

int n;

int main(){
	cin >> n;
	vector<int> A(n);
	rep(i,n)cin >> A[i];
	shellsort(A,n);
	cout << cnt << endl;
	rep(i,n)cout << A[i] << endl;
}
