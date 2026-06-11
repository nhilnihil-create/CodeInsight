#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[300010],b[300010],x[300010],y[300010],ans,c,d,f,aa,bb;
int main(){
	cin>>n>>m>>k;
	for (int i=0;i<k;i++){
		cin>>x[i]>>y[i];
		a[x[i]]++;
		b[y[i]]++;
	}
	for (int i=1;i<=n;i++) c=max(c,a[i]);
	for (int i=1;i<=n;i++) if (a[i]==c) aa++;
	for (int i=1;i<=m;i++) d=max(d,b[i]);
	for (int i=1;i<=m;i++) if (b[i]==d) bb++;
	for (int i=0;i<k;i++) if (a[x[i]]==c&&b[y[i]]==d) f++;
	if (f==aa*bb)
		cout<<c+d-1<<endl;
	else
		cout<<c+d<<endl;
	return 0;
}