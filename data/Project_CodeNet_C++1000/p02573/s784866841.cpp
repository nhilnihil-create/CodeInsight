#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define debug cout << "Ok" << endl;

using namespace std;

void solve(){

	return;
}


vector<int>ps(200100);
vector<int>qtd(200100,1);

int find_set(int n){
	return (ps[n]==n ? n : ps[n] = find_set(ps[n]));
}
int ma=1;

bool insert(int x, int y){
	int xr = find_set(x);
	int yr = find_set(y);
	int l;

	if(xr == yr) return false;

	if(qtd[xr] < qtd[yr]){
		l = xr;
		xr = yr;
		yr = l;
	}

	ps[yr]=xr;
	qtd[xr]+=qtd[yr];
	ma = max(ma,qtd[xr]);
	return true;
}

int32_t main(){
	long long int n,m,a,b;

	cin >> n >> m;
	for(int i=0;i<=n+3;i++){
		ps[i]=i;
	}
	while(m--){
		cin >> a >> b;
		insert(a,b);
	}


	cout << ma << endl;
	return 0;
}