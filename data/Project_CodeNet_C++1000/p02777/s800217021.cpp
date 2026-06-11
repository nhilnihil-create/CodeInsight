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

	string s1,s2,s3;
	int n,m;

	cin >> s1 >> s2 >> n >> m;
	map<string,int>ma;
	cin >> s3;
	ma[s1]=n;
	ma[s2]=m;
	
	ma[s3]--;

	cout << ma[s1] << " " << ma[s2] << endl;


	return 0;
}