#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define maxn 51
#define m_p make_pair

int main(){
	int n;
	cin>>n;
	int x[maxn],y[maxn];
	map<pii,int> mp;
	for (int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		mp[m_p(x[i],y[i])]=1;
	}
	int res=n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i==j) continue;
			int dx=x[i]-x[j];
			int dy=y[i]-y[j];
			int cnt=0;
			for (int k=0;k<n;k++)
				if (mp.count(pii(x[k]+dx,y[k]+dy))) cnt++;
			res=min(res,n-cnt);
		}
	}
	printf("%d\n",res);
	return 0;
} 