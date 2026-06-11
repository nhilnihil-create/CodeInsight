#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	//ofstream cout ("fileName.txt");
	//ifstream cin ("fileName.txt");
 	
	ll n;
	cin>>n;
	
	int length=0;
	for(int k=10; k>=1; k/=2)
		while(26*(pow(26,length+k)-1)/(25)<n) 
			length+=k;
			
	++length;
	
	n-=(pow(26,length)-1)/25;
	
	string s="";
	
	while(length--) {
		s+='a'+char(n%26);
		n/=26;
	}
	
	reverse(s.begin(),s.end());
	cout<<s<<"\n";

	return 0;
}
