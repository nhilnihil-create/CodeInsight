#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int,int>;

#define ff first
#define ss second

const ll INF = 1e12+10;

int main(){
	ll n,k,min_ans=INF;
	cin >> n >> k;
	vector<ll> A(n),F(n);
	for(int i=0;i<n;++i){
		cin >> A[i];
	}
	for(int i=0;i<n;++i){
		cin >> F[i];
	}
	sort(A.begin(),A.end());
	sort(F.rbegin(),F.rend());
	ll lo = 0,hi = INF,mid;
	while(lo<hi){
		mid = (lo+hi)/2;
		ll s=0;
		for(int i=0;i<n;++i){
			if(A[i]-mid/F[i] >= 0)
				s+=A[i]-mid/F[i];
		}
		if(s <= k)
			hi = mid;
		else
			lo = mid+1;
	}
	cout << lo << '\n';
	return 0;
}