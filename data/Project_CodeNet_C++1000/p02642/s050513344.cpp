#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int a[1000010];
int b[1000010];
int c[1000010];
bool flg[1000010];
int main(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	// for(int i=1;i<=n;i++){
	// 	int x=a[i],j=2;
	// 	int flg=1;
	// 	memset(c,0,sizeof c);
	// 	vector<int>cur;
	// 	while(x>1){
	// 		if(x%j==0){
	// 			if(b[j])flg=0;
	// 			x/=j;
	// 			cur.pb(j);
	// 		}else j++;
	// 	}
	// 	for(auto x:cur)b[x]++;
	// 	if(a[i]!=a[i-1]&&a[i]!=a[i+1])ans+=flg;
	// }
	// cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(!flg[x]&&a[i]!=a[i-1]&&a[i]!=a[i+1])ans++;
		if(!flg[x])for(int j=1;x*j<=1000000;j++)flg[x*j]=1;
	}
	cout<<ans<<endl;
	return 0;
}
