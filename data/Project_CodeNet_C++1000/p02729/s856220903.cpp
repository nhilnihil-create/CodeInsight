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

int solve(int n){

	return ( (n-1) * n) /2;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;


	cin >> n >> m;

	cout << solve(n) + solve(m) << endl;	
	return 0;
}