#include <bits/stdc++.h>
using namespace std;
#include <math.h> 
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b;
	cin>>a>>b;
	string s,t;
	for(ll i=0;i<b;i++){
		char now=char(a+'0');
		s.push_back(now);
	}
	for(ll i=0;i<a;i++){
		char now=char(b+'0');
		t.push_back(now);
	}
	if(s<t){
		cout <<s;
	}
	else{
		cout <<t;
	}
	// your code goes here
	return 0;
}