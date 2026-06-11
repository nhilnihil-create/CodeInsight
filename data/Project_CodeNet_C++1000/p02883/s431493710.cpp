#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

bool chk(vector<ll> &a, vector<ll> &f, ll t, ll k){
	int n = a.size();
	if(t<0) return false;
	for(int i=0; i<n; i++){
		if(a.at(i)*f.at(i)>t){
			ll c=(a.at(i)*f.at(i)-t+f.at(i)-1)/f.at(i);
			if(k<c) return false;
			k-=c;
		} 
	}
	return true;
}

int main(){
	
	int n; ll k; cin>>n>>k;
	vector<ll>a(n),f(n);
	for(int i=0; i<n; i++) cin>>a.at(i);
	for(int i=0; i<n; i++) cin>>f.at(i);
	sort(a.rbegin(),a.rend());
	sort(f.begin(),f.end());
	ll ok=1e12,ng=-1, mid;
	while(abs(ok-ng)>1){
		mid = (ok+ng)/2;
		(chk(a,f,mid,k)?ok:ng)=mid;
	}
	cout << ok << endl;
}
