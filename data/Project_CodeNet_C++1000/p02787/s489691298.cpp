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

void solve(){

	return;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long int n,m,j=1,a,b,resp=1000000000;
	
	cin >> n >> m;

	vector<long long int>v(20000000 ,  1000000000000);
	vector<pair<long long int, long long int>>l;
	v[0]=0;

	for(int i=0;i<m;i++){
		cin >> a >> b;

		j=0;
		while(j+a<n+a+300){
			v[j+a] = min(v[j+a], b + v[j]);
			j++;

		}

	}

	sort(all(l));

	resp = v[n];

	for(int i=n;i<v.size();i++){
		resp = min(resp, v[i]);
	}

	cout << resp << endl;
	return 0;
}