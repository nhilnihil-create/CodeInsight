#include<bits/stdc++.h>
using namespace std;
int n;
int a;
int c[300100],d[300100];
long long prekdk[300100],sufdk[300100],func[300100];
int main(){
	#ifdef FILIN
		#ifndef LOCAL
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		c[a]++;
	}
	for(int i=1;i<=n;i++)
		d[c[i]]++;
	for(int i=1;i<=n;i++)
		prekdk[i]=prekdk[i-1]+(long long)(i)*(long long)(d[i]);
	for(int i=n;i>=1;i--)
		sufdk[i]=sufdk[i+1]+(long long)(d[i]);
	for(int i=1;i<=n;i++)
		func[i]=(long long)(prekdk[i]/(long long)(i)+sufdk[i+1]);
	sort(func+1,func+n+1);
	int res;
	for(int i=1;i<=n;i++){
		res=(int)(lower_bound(func+1,func+n+1,(long long)(i))-func);
		cout<<n+1-res<<endl;
	}
	return 0;
}
