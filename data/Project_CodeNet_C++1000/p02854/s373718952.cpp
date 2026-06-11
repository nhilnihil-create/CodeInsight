#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979
using ll = long long;
using P = pair<int,int>;

ll divisor=1e9+7;
int main(){
	int n;
	cin>>n;
	int a[n];
	ll sum=0;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	ll sum2=0;
	ll ans=sum;
	rep(i,n){
		ans=min(ans,abs(sum-sum2*2));
		sum2+=a[i];
	}
	ans=min(ans,abs(sum-sum2*2));
	puts(ans);
}