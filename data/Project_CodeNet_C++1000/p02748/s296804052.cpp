#include <bits/stdc++.h>
#define ll				long long int
#define fast			ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
#define vi 			vector<int>
#define vll 			vector<long long int>
#define all(v)			v.begin(),v.end()
const ll MOD = 1e9 + 7;
const ll INF = 10000000000000000;
const ll MAX_N = 1e5 + 7;
using namespace std;
//vector<bool> h(10000001,1);



int main(){
	int a,b,m;
	cin >> a >> b >> m;
	vll v1(a),v2(b);
	for(int i=0;i<a;i++)cin >> v1[i];
	for(int j=0;j<b;j++)cin >> v2[j];
	ll k = *min_element(all(v1))+*min_element(all(v2));
	
	ll sum = INT_MAX;
	for(int i=0;i<m;i++){
		ll a,b,c;
		cin >> a >> b >> c;
		a--,b--;
		sum=min(sum,v1[a]+v2[b]-c);
	
	}
	cout << min(k,sum); 
}

