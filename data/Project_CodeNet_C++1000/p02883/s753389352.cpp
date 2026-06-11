#include<bits/stdc++.h>
//by Davidshx
using namespace std;
int n;
long long k,a[200100],f[200100],le,ri,mx,kk,mi;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(a+1,a+n+1);sort(f+1,f+n+1);reverse(f+1,f+n+1);
	for(int i=1;i<=n;i++) mx=max(a[i]*f[i],mx);
	le=0;ri=mx;
	while(le<ri){
		kk=k;mi=(le+ri)/2LL;
		for(int i=1;i<=n;i++) if(a[i]*f[i]>mi) kk-=(a[i]-mi/f[i]);
		if(kk<0LL) le=mi+1LL; else ri=mi; 
	}
	cout<<le<<endl;
	return 0;
}
