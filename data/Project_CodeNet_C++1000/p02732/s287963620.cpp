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

long long int som(long long int n){

	return (n*(n-1))/2;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	map<int,long long int>qtd;
	long long int n,cont=0;
	cin >> n;
	vector<int>v(n);

	for(int i=0;i<n;i++){
		cin >> v[i];
		qtd[v[i]]++;
	}

	for(auto i = qtd.begin();i!=qtd.end();i++){
		cont+= som(i->second);
		i->second--;
	}

	for(int i=0;i<n;i++){
		cout << cont - qtd[v[i]] << endl;
	}

	return 0;
}