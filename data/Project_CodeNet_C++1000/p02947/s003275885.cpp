// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	int n;
	cin>>n;
	string s[n];
	map<string,int>m;
	for(int i = 0; i < n ; i++){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		m[s[i]]++;
	}
	ll ans = 0;
	for(auto it :m){
		if(it.second <= 0)continue;
        for(int i = 1;i < it.second;i++)
        	ans += i;
	}
	cout<<ans<<endl;
	
}