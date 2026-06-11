#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define maxn 51
#define m_p make_pair

int main(){
	int n;
	cin>>n;
	int x[maxn],y[maxn];
	set<pii> st;
	for (int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		st.insert(m_p(x[i],y[i]));
	}
	int res=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (i==j) continue;
			int dx=x[i]-x[j];
			int dy=y[i]-y[j];
			int cnt=0;
			for (int k=0;k<n;k++){
				pii qq=pii(dx+x[k],dy+y[k]);
				if (st.count(qq)) cnt++;
			}
			res=max(res,cnt);
		}
	printf("%d\n",n-res);
	return 0;
}