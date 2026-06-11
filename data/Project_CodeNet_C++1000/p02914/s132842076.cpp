#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
int n;
ll a[100010];
ll b[100010];
bool check(vector<ll> c, ll x){
	bool used[60]={};
	int m=c.size();
	if(m==0){
		if(x==0) return true;
		else return false;
	}
	for(int i=0; i<m; i++){
		int j1=-1;
		for(int j=0; j<60; j++){
			if(used[j]) continue;
			if(c[i]&(1ll<<j)){
				j1=j; break;
			}
		}
		if(j1==-1) continue;
		used[j1]=1;
		for(int k=0; k<60; k++){
			if(k==j1) continue;
			if(c[i]&(1ll<<k)){
				for(int l=0; l<m; l++){
					if(c[l]&(1ll<<j1)){
						c[l]^=(1ll<<k);
					}
				}
				if(x&(1ll<<j1)) x^=(1ll<<k);
			}
		}
	}
	for(int i=0; i<60; i++){
		if((x&(1ll<<i)) && !used[i]) return false;
	}
	return true;
}
int main()
{
	cin>>n;
	ll s=0;
	for(int i=0; i<n; i++){
		cin>>a[i];
		s^=a[i];
		b[i]=a[i];
	}
	bool used[60]={};
	vector<P> v;
	for(int i=0; i<n; i++){
		int j1=-1;
		for(int j=0; j<60; j++){
			if(used[j]) continue;
			if(b[i]&(1ll<<j)){
				j1=j; break;
			}
		}
		if(j1==-1) continue;
		used[j1]=1;
		for(int k=0; k<60; k++){
			if(k==j1) continue;
			if(b[i]&(1ll<<k)){
				for(int l=0; l<n; l++){
					if(b[l]&(1ll<<j1)){
						b[l]^=(1ll<<k);
					}
				}
				v.push_back({j1, k});
			}
		}
	}
	ll ans=0;
	ll c[60];
	for(int i=0; i<60; i++) c[i]=(1ll<<i);
	for(int i=0; i<60; i++){
		for(auto p:v){
			int j=p.first, k=p.second;
			if(c[i]&(1ll<<j)) c[i]^=(1ll<<k);
		}
	}
	for(int i=0; i<60; i++){
		if(used[i]){
			for(int j=0; j<60; j++) if(c[j]&(1ll<<i)) c[j]^=(1ll<<i);
		}
	}
	for(int i=59; i>=0; i--){
		if(s&(1ll<<i)) continue;
		ll x=ans^(1ll<<i);
		for(auto p:v){
			int j=p.first, k=p.second;
			if(x&(1ll<<j)) x^=(1ll<<k);
		}
		for(int j=0; j<60; j++){
			if(used[j]){
				if(x&(1ll<<j)) x^=(1ll<<j);
			}
		}
		vector<ll> vc;
		for(int j=0; j<60; j++) if(j<i || s&(1ll<<j)) vc.push_back(c[j]);
		if(check(vc, x)){
			ans^=(1ll<<i);
		}
	}
	cout<<s+2*ans<<endl;
	return 0;
}