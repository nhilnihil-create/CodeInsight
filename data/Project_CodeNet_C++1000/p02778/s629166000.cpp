#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define en "\n"
#define eps 1e-9
#define VECT(v)  vector<int>v
#define SCAN(v)  int temp; for(int i=0; i<n; i++) {cin>>temp; v.push_back(temp);}
#define PRINT(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << en;
#define SORT(v)  sort(v.begin(), v.end());
#define CASEP(v) cout<<"Case "<<tc<<": "<<v<<"\n"
#define DEBUG(v) cout << v << " "; cout << en;

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	string s;
	cin >> s;

	for(int i = 0; i < s.size(); i++)
		cout << "x";
	cout << en;

	return 0;
}