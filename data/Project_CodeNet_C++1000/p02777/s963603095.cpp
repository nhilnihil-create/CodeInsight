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

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin>>s>>t;
	int a,b;
	cin>>a>>b;
	string u;
	cin>>u;
	if(u==s)
		a--;
	else
		b--;
	cout<<a<<" "<<b<<endl;
	return 0;
}