#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,c;
int f[N],g[N],nex[N],pre[N],h[N];
string s;
int main() {
	int l,i,cnt,cnt1,last,k;
	ios::sync_with_stdio(false);
	cin>>n>>k>>c>>s; c++; l=s.length();
	last=-1;
	for (i=0;i<l;i++) 
		if (s[i]=='x') f[i]=(i==0?0:f[i-1]);
		else {
			f[i]=1; if (i>=c) f[i]+=f[i-c];
			pre[i]=last; last=i;
		}
	last=-1;
	for (i=l-1;i>=0;i--)
		if (s[i]=='x') g[i]=g[i+1];
		else {
			g[i]=1; if (i+c<l) g[i]+=g[i+c];
			nex[i]=last; last=i;
		}
	for (i=0;i<l;i++)
		if (s[i]=='o') {
			h[i]=f[i];
			if (i+c<l) h[i]+=g[i+c];
//			cout<<i<<' '<<h[i]<<endl;
		}
	for (i=0;i<l;i++) 
		if (s[i]=='o') {
//			cout<<i<<' '<<pre[i]<<' '<<nex[i]<<endl;
			cnt=h[i];
			if (cnt!=k) continue;
//			if ((pre[i]==-1||i-pre[i]>=c)&&(nex[i]==-1||nex[i]-i>=c)) {
//				cout<<i+1<<endl;
//				continue;
//			}
			if (pre[i]==-1) cnt1=g[i+1];
			else cnt1=h[pre[i]];
			if (pre[i]!=-1&&i-pre[i]>=c) cnt1--;
			if (cnt1==k) continue;
			if (nex[i]==-1) cnt1=(i==0?0:f[i-1]);
			else cnt1=h[nex[i]];
			if (nex[i]!=-1&&nex[i]-i>=c) cnt1--;
			if (cnt1==k) continue;
			cout<<i+1<<endl;
		}
	return 0;
}