#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
int ans[520][520];
void divide(vector<int> a,int dep){
	int n = a.size();
	if(n<=1)return ;
	vector<int> x,y;
	for(int i=0;i<n;i++){
		if(i<n/2)x.pb(a[i]);
		else  y.pb(a[i]);
	}
	for(int i:x)for(int j:y)ans[i][j] = dep;
	divide(x,dep+1);
	divide(y,dep+1);
}
int main()
{
	int n;cin>>n;
	vector<int> tmp;
	for(int i=1;i<=n;i++)tmp.pb(i);
	divide(tmp,1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}
