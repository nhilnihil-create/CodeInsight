//#pragma GCC optimize(2) 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define clr(a,b) memset(a,b,sizeof(a))

ll n,m,k,ans;
char c[10005];
ll p,q,r;
int main(){
	//freopen("P1429_6.in","r",stdin);
	//freopen("match.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='R')p++;
		if(c[i]=='G')q++;
		if(c[i]=='B')r++;
	}
	ans=p*q*r;
	for(int i=1;i<=n;i++){
		for(int d=1;i+2*d<=n;d++){
			int j=i+d,k=i+2*d;
			if(c[i]!=c[j]&&c[j]!=c[k]&&c[k]!=c[i])ans--;
		}
	}
	cout<<ans<<"\n";
    return 0;
}