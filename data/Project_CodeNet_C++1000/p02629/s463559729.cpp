#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+5;
vector<string>v;
void solve(){
	ll n; 
	cin>>n;
	string s = ""; 
	while(n>0){
		if(n)n--;
		else break;
		int x = n%26;
		n/=26;
		s+=char('a'+x);
	}
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
