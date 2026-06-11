#include <bits/stdc++.h>
using namespace std;
#include <math.h> 
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,m;
	cin>>n>>m;
	string s,t;
	for(ll i=0;i<n;i++){
		s+='0'+m;
	}
	for(ll i=0;i<m;i++){
		t+='0'+n;
	}
	if(s<t){
		cout <<s;
	}
	else{
		cout << t;
	}
	// your code goes here
	return 0;
}