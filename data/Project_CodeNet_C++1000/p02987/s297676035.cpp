#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i = x;i<n;i++)
#define S(v) sort(v.begin(), v.end());
#define ff first
#define ss second


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	// freopen("in.txt","r", stdin);
	set<char> s;
	loop(i,0,4){
		char x;
		cin>>x;
		s.insert(x);
	}
	cout<<(s.size() == 2?"Yes":"No");
}