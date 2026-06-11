#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define ll long long
#define double long double
#define MAX (int)(2*pow(10,5) + 10)
#define N 100000
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,9);
ll modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;

void deal(){
	ll k,n;
	cin>>n>>k;
	if(k==1)
		cout<<0;
	else
		cout<<(n-k);
	
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
