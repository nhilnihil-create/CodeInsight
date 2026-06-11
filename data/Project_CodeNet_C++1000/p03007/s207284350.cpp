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
#define forx(v) for(ll x=0; x<v; x++)
#define ll long long
#define double long double
#define MAX (int)(2*pow(10,5) + 10)
#define N 100000
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;

void deal(){
	ll n ;
	cin>>n;
	vector<ll> to[2];
	vector<ll> arr(n);
	fori(n){
		ll ed;
		cin>>ed;
		arr[i] = ed;
		to[(ed>=0)].pb(ed);
	}
	swap(to[0], to[1]);
	fori(2)
		sort(to[i].begin(), to[i].end());
	reverse(to[1].begin(),to[1].end());
	if(to[0].size() && to[1].size()){
		ll s = 0;
		for(auto& el: arr)
			s+=fabs(el);
		cout<<s<<'\n';
		while(to[0].size() > 1){
			ll lst = to[0][to[0].size()-1];
			cout<<to[1][0]<<' '<<lst<<'\n';
			to[1][0]-=lst;
			to[0].erase(to[0].end()-1);
		}
		while(to[1].size()){
			ll lst = to[1][to[1].size()-1];
			cout<<to[0][0]<<' '<<lst<<'\n';
			to[0][0]-=lst;
			to[1].erase(to[1].end()-1);
		}
	}
	else if(to[0].size()){
		ll s = -to[0][0];
		for(ll i =1 ;i<to[0].size(); i++)
			s+=to[0][i];
		cout<<s<<'\n';
		for(ll i = 2; i<to[0].size(); i++){
			cout<<to[0][0]<<' '<<to[0][i]<<'\n';
			to[0][0] -= to[0][i];
		}
		cout<<to[0][1]<<' '<<to[0][0]<<'\n';
	}
	else{
		ll s = to[1][0];
		for(ll i =1 ;i<to[1].size(); i++)
			s-=to[1][i];
		cout<<s<<'\n';
		for(ll i = 2; i<to[1].size(); i++){
			cout<<to[1][0]<<' '<<to[1][i]<<'\n';
			to[1][0] -= to[1][i];
		}
		cout<<to[1][0]<<' '<<to[1][1]<<'\n';
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

/*

5
-3 -2 -6 -1 -5

*/