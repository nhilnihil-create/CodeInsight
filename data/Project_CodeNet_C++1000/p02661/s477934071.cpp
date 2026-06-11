#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ss second
#define ff first
#define N 200005
#define inf 1000000009
#define ll long long
#define pii pair<int,int>
#define sz(a) int(a.size())
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int n,a[N],b[N];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d",&a[i],&b[i]);		
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	if(n % 2 == 1) printf("%d",b[(n+1)/2]-a[(n+1)/2]+1);
	else {
		int ma = a[n/2+1] + a[n/2];
		int mb = b[n/2+1]+b[n/2];
		printf("%d",mb - ma + 1);
	}
}
