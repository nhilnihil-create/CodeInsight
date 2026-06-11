#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

vector<ll>divisor(ll n){
	vector<ll>res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.push_back(i);
			if(i!=n/i)res.push_back(n/i);
		}
	}
	return res;
}

int a[600];

int main(){
	int n,K;cin>>n>>K;
	int sum=0;
	rep(i,n){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	auto v=divisor(sum);
	int Max=0;
	for(int m:v){
		int cnt=0;
		rep(i,n){
			cnt+=a[i]%m;
		}
		if(cnt%m)continue;
		ll A=0;
		sort(a,a+n,[&](int b,int c){return b%m>c%m;});
		rep(i,min(n,cnt/m)){
			A+=m-a[i]%m;
		}
		A+=max(0,cnt/m-n)*m;
		if(A<=K)Max=max(Max,m);
	}
	cout<<Max<<endl;
}