#include<bits/stdc++.h>
using namespace std;

#define NINJA ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define dloop(i,n) for(int i=n-1;i>=0;i--)
#define iii tuple<int,int,int>
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define int long long
#define pb push_back
#define endl "\n"
#define setbits __builtin_popcountll
#define mp map<int,int>
#define F first
#define S second
#define sz(v) (int)v.size()
#define mod 1000000007
#define inf (int)1e18

int32_t main(){
	NINJA;

	int n; cin >> n;
	multiset<double> a;
	fo(i,n){
		double x; cin >> x;
		a.insert(x);
	}

	if(sz(a)==1){
		cout << *a.begin() << endl;
		return 0;
	}

	// sort(a.begin(), a.end());
	while(sz(a)>1){
		double f = *a.begin();
		a.erase(a.begin());
		double s = *a.begin();
		a.erase(a.begin());
		double m = (f+s)/2;
		a.insert(m);
	}

	cout << *a.begin() << endl;
	
	return 0;
}