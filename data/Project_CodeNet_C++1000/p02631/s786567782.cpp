#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define SZ(x) (int)x.size()
#define ll long long
#define pb push_back
#define pq priority_queue
#define pii pair<int,int>
#define mod 998244353
#define inf 0x3f3f3f3f
#define debug(x) cerr<<#x<<"="<<x<<'\n'
#define rep(i,a,b) for (int i=a;i<(b);i++)

const int maxn=2e5+10;

int n;
int a[maxn];
int sum=0;

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	rep(i,0,n) cin>>a[i],sum^=a[i];
	rep(i,0,n) cout<<(a[i]^sum)<<" ";
 	return 0; 
}
