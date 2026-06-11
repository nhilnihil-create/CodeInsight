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
 
using namespace std;

double solve(double n){

	double cont=0;

	for(int i=1;i<=n;i++){
			cont+=i;
	}

	return 1.0*cont/n;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	vector<double>v;
	v.push_back(0);

	int n,m;
	double aux,resp=0*1.0;

	cin >> n >> m;

	for(int i=0;i<n;i++){
		cin >> aux;
		v.push_back(v[i] + solve(aux));
	}

	for(int i=m;i<=n;i++){
			resp = max(resp, v[i]-v[i-m]);
	}

		cout << setprecision(9) << resp << "\n";
	return 0;
}