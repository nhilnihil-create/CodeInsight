#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	ll a[1000010];
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	ll ans=1;
	vector<ll>sel;
	for(ll i=1;i<=sqrt(sum);i++){
		if(sum%i!=0){
			continue;
		}
		sel.push_back(i);
		sel.push_back(sum/i);
	}
	for(ll i=0;i<sel.size();i++){
//		cout << sel[i]<<" ";
		vector<ll>b;
		ll sum2=sel[i]*n;
//		cout << sum2 ;
		for(ll j=0;j<n;j++){
			ll now=a[j]%sel[i];
			b.push_back(now);
			sum2-=now;
			if(now==0){
				sum2-=sel[i];
			}
		}
//		cout <<"k"<< sum2 <<endl;
		if(sum2<=k){
			ans=max(ans,sel[i]);
			continue;
		}
		sort(b.begin(),b.end());
		ll sum3=0;
		for(ll j=0;j<n;j++){
			sum3+=b[j];
			if(b[j]!=0){
				sum2-=sel[i]-b[j];
			}
		//	cout <<"s"<< sum2<< " ";
			if(max(sum2,sum3)<=k){
				ans=max(ans,sel[i]);
				break;
			}
		}
	//	cout <<endl;
	}
	cout <<ans;
	// your code goes here
	return 0;
}