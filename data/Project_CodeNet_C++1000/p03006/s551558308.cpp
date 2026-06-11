#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define maxn 51
#define m_p make_pair

int main(){
	int n;
	cin>>n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i=0;i<n;i++) cin>>x[i]>>y[i];
	if (n==1){
		cout<<n<<endl;
		return 0;
	}
	int res=n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (i==j) continue;
			int dx=x[j]-x[i];
			int dy=y[j]-y[i];
			int cnt=0;
			for (int k=0;k<n;k++)
				for (int l=0;l<n;l++)
					if (dx==x[l]-x[k] && dy==y[l]-y[k])
						cnt++;
			res=min(res,n-cnt);
		}
	printf("%d\n",res);
	return 0;
}