#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int,int> pii;

int n;
ll x[51],y[51];
set<pii> st;

int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
	if (n==1){
		cout<<1<<endl;
		return 0;
	}
	ll ans=n+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (x[i]==x[j] && y[i]==y[j]) continue;
			if (x[i]>x[j]) continue;
			ll p=x[j]-x[i],q=y[j]-y[i];
			
			st.clear();
			for (int i=1;i<=n;i++)
				st.insert(make_pair(x[i],y[i]));
			ll tmp=0;
			pii pre;
			bool first=true;
			while (st.size()){
				pii nx=make_pair(pre.first+p,pre.second+q);
				if (!first && st.count(nx)){
					pre=nx;
					st.erase(nx);
				}
				else{
					pre=*st.begin();
					st.erase(st.begin());
					tmp++;
				}
				first=false;
			}
			//cout<<p<<" "<<q<<endl;
			ans=min(ans,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}