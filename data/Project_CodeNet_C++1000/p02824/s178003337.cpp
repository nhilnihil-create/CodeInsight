#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define forx(v) for(int x=0; x<v; x++)
#define ll long long
#define lll __int128
#define MAX (int)(4*pow(10,3) + 100)
#define pb(a) push_back(a)
#define ch (int)(4*pow(10,4) + 100)
#define ld long double
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10,9)+7 ;
double eps = 1e-9;
ifstream in;
ofstream out;




void deal(){
	ll n, m, v, p;
	cin>>n>>m>>v>>p;
	v = v-(p-1)-1;
	ll ans = p-1;
	vector<ll> arr(n);
	fori(n){
		cin>>arr[i];
	}
	sort(arr.rbegin(), arr.rend());
	{
		vector<ll> arr2;
		for(ll i = p-1; i<arr.size(); i++){
			arr2.pb(arr[i]);
		}
		arr = arr2;
	}
	
	
	n = arr.size();
	
/*	fori(n){
		cout<<arr[i]<<' ';
	}
	cout<<endl;
*/	
	ll lo = 0, hi = n-1;
	// last one that satisfies
	while(lo < hi){
		ll mid = (lo+hi)/2+1;
		ll ed = arr[mid] + m;
		ll s = 0;
		fori(n){
			if(i == mid){
				continue;
			}
			s+=min(m, ed-arr[i]);
		}
		if(v<=0){
			s = m;
		}
		else{
			s /= v;
		}
		if(s >= m && ed>=arr[0]){
			// we good
			lo = mid;
		}
		else{
			hi = mid-1;
		}
		
	}
	
	ans += lo+1;
	
	cout<<ans;
	
	
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}



/* 
6 8 
1 2
2 3
3 4
4 1
2 5
3 5
1 6
4 6
*/