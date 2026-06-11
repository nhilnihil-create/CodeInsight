#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,k,c;
	cin>>n>>k>>c;
	string s;
	cin>>s;
	ll l[200010]={},r[200010]={};
	for(ll i=0;i<n;i++){
		if(s[i]=='o'){
			l[0]=i;
			break;
		}
	}
	for(ll i=1;i<k;i++){
		ll now=l[i-1]+c;
		for(ll j=now+1;j<n;j++){
			if(s[j]=='o'){
				l[i]=j;
				break;
			}
		}
	}
	for(ll i=n-1;i>=0;i--){
		if(s[i]=='o'){
			r[k-1]=i;
	//		cout << i<<endl;
			break;
		}
	}
//	cout <<endl;
	for(ll i=k-2;i>=0;i--){
		ll now=r[i+1]-c;
		for(ll j=now-1;j>=0;j--){
			if(s[j]=='o'){
				r[i]=j;
		//		cout << j<<endl;
				break;
			}
		}
	}
//	cout <<endl;
	for(ll i=0;i<k;i++){
		if(r[i]==l[i]){
			cout << r[i]+1<<endl;
		}
	}
	// your code goes here
	return 0;
}