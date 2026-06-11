#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

typedef long long ll;

void solve(){
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	while(b<=a && k){
		b*=2;
		k--;
	}	
	while(c<=b && k){
		c*=2;
		k--;
	}	
	if(a<b && b<c)cout<<"Yes";
	else cout<<"No";
}

int main(){
	Red;
	int T=1;
	//cin>>T;
	while(T--)solve();
}