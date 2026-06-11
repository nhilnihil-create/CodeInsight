#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;

const int N = 200005;

int n,k;
ll a[N],c[N];
int addd[N];

map<ll,int> mp;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i] = c[i-1] + a[i];
	}
	ll ans = 0;
	mp[0] = 1;
	for(int i=1;i<=n;i++){
		if(i-(k-1) > 0){
			mp[addd[i-k]]--;
		}
		int h = (c[i]-i)%k;
		h += k;
		h %= k;
		ans += mp[h];
		
		addd[i] = h;
		//cout<<i<<" "<<c[i]<<" "<<h<<" "<<mp[h]<<" "<<addd[i]<<endl;
		mp[h]++;
		
	}
	
	cout<<ans;
	
	return 0;
}
