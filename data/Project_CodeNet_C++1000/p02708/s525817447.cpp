#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001
#define INF         INT_MAX

int32_t main(){

	int n,k;
	cin>>n>>k;
	
	int sum1=0,sum2=0;
	for(int i=0;i<k;i++){
		sum1+=i;
		sum2+=n-i;
	}

	// cout<<sum1<<"  "<<sum2<<endl;
	int ans=(sum2-sum1+1)%mod;
	for(int i=k;i<=n;i++){

		sum1+=i;
		sum2+=n-i;

		// cout<<sum1<<"  "<<sum2<<endl;
		ans+=(sum2-sum1+1)%mod;
		ans=ans%mod;

	}
	cout<<ans%mod<<endl;
	return 0;
}