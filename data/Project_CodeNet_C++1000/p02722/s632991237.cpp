#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
#define X first
#define Y second
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
const int maxn=1e4+10;
int a[maxn];
//个人觉得这一题可以通过搜索去解决。。。。

ll ans;
ll n,k;
set<int>st;

vector<ll>solve(ll n){
	vector<ll>res;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			res.push_back(i);
			if(n/i!=i){
				res.push_back(n/i);
			}
		}
	}
	res.push_back(n);
	return res;
}


int main(){
	ll n;
	cin>>n;
	//下面分成是约数，与不是约数两种情况来讨论
	//不是约数的情况，那么那个数就是n-1的约数
	if(n==2){
		cout<<1<<endl;
		return 0;
	}
	ll ans=0;
	//不是约数，那么只要n%k==1就可以啦.所以n=k*x+1.所以(n-1)%x==k.
	vector<ll>a=solve(n-1);
	for(int i=0;i<a.size();i++){
		if(n%a[i]==1)ans++;
	}
	//下面就是是约数的情况
	vector<ll>b=solve(n);
	for(int i=0;i<b.size();i++){
		ll temp=n;
		while(temp%b[i]==0)temp=temp/b[i];
		if(temp%b[i]==1)ans++;
	}
	cout<<ans<<endl;
	return 0;
}