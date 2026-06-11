#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	string s;
	cin>>s;
	s.erase(unique(s.begin(),s.end()),s.end());
	cout<<s.size();
	return 0;
}
