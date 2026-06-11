#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = (ll)1e9 + 7;
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)

signed main() {
	ll N;
	string S;
	cin>>N>>S;

	if(S[0]=='W'||S[S.size()-1]=='W'){
		cout<<0<<endl;
		return 0;
	}

	vector<ll> left(2*N,0),right(2*N,0);
	ll count=0;
	rep(i,2*N){
		if(S[i]=='B'){
			if(count%2==1){
				right[i]=1;
				count--;
			}else{
				left[i]=1;
				count++;
			}
		}else{
			if(count%2==1){
				left[i]=1;
				count++;
			}else{
				right[i]=1;
				count--;
			}
		}
	}

	ll lsum=accumulate(left.begin(),left.end(),0LL);
	ll rsum=accumulate(right.begin(),right.end(),0LL);
	if(lsum!=rsum){
		cout<<0<<endl;
		return 0;
	}

	vector<ll> ruileft(2*N+1,0);
	rep(i,2*N){
		ruileft[i+1]=ruileft[i]+left[i];
	}

	ll ans=1,rcount=0;
	rep(i,2*N){
		if(right[i]){
			ll candidate=ruileft[i]-rcount;
			ans*=candidate;
			ans%=MOD;
			rcount++;
		}
	}

	rep(i,N){
		ans*=(i+1);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
