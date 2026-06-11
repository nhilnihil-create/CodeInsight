#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[110],b[110];
int main(){
	ll n;
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(i>=3){
			if(a[i-2]==b[i-2]&&a[i-1]==b[i-1]&&a[i]==b[i])f=1;
		}
	}
	cout<<(f?"Yes":"No");
	return 0;
}
