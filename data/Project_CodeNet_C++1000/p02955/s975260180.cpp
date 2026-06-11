#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k,a[500];
	cin>>n>>k;
	ll sum1=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		sum1+=a[i];
	}
//	cout <<sum1<<endl;
	vector<ll>sq;
	for(ll i=1;i<=sqrt(sum1);i++){
		if(sum1%i==0){
			sq.push_back(i);
			sq.push_back(sum1/i);
		}
	}
	sort(sq.begin(),sq.end());
	reverse(sq.begin(),sq.end());
	for(ll i=0;i<sq.size();i++){
		ll now=sq[i];
//		cout <<now<<endl;
		vector<ll>b;
		ll sum2=0;
		for(ll j=0;j<n;j++){
			b.push_back(abs(now-a[j]%now));
			sum2+=b[j];
			//cout << b[j]<<" ";
		}
		sort(b.begin(),b.end());
		reverse(b.begin(),b.end());
//		cout <<endl;
		ll sum3=0;
		for(ll j=0;j<n;j++){
			sum2-=b[j];
			sum3+=abs(now-b[j]);
			if(now==7){
		//		cout << sum2<<" "<<sum3<<endl;
			}
			if(max(sum3,sum2)<=k){
				cout <<now;
				return 0;
			}
		}
	}
	// your code goes here
	return 0;
}