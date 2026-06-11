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
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string,int>ma;
	int n,maior=0;
	string s;
	cin >> n;

	while(n--){
		cin >> s;
		ma[s]++;
		maior = max(maior,ma[s]);
	}

	for(auto i: ma){
		if(i.second == maior){
			cout << i.first << endl;
		}
	}
	
	return 0;
}