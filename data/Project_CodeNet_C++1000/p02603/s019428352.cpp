#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
const int maxn=200010;
int n,ans=1000;
int a[maxn];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1])ans+=ans/a[i-1]*(a[i]-a[i-1]);
	}
	cout<<ans<<endl;
}
