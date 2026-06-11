#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll ch[100010];
	for(ll i=0;i<n;i++){
		cin>>ch[i];
	}
	bool ans=true;
	for(ll i=n-2;i>=0;i--){
		if(ch[i+1]<ch[i]){
			ch[i]--;
		}
		if(ch[i+1]<ch[i]){
			ans=false;
		}
	}
	cout << (ans?"Yes":"No");
	// your code goes here
	return 0;
}