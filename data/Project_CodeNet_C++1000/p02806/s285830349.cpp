#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;

int n,q;
ll a[N];
string s[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>a[i];
	}
	string x;
	cin>>x;
	ll ans = 0;
	for(int i=n-1;i>=0;i--){
		if(s[i] == x)break;
		ans += a[i];
	}
	cout<<ans;
	
	
	return 0;
}

