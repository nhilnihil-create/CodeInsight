#include<bits/stdc++.h>
using namespace std;

#define hell 1e9


int main(){
	int h,w,m;
	cin>>h>>w>>m;
	int x[m],y[m];
	for(int i=0;i<m;i++){
		cin>>x[i]>>y[i];
	}
	int r[h],c[w];
	for(int i=0;i<h;i++){
		r[i]=0;
	}
	for(int i=0;i<w;i++){
		c[i]=0;
	}
	for(int i=0;i<m;i++){
		r[x[i]-1]++;
		c[y[i]-1]++;
	}
	int mx=0,mx1=0;
	for(int i=0;i<h;i++){
		mx=max(r[i],mx);
	}
	for(int i=0;i<w;i++){
		mx1=max(c[i],mx1);
	}
	int ans=mx+mx1;
	int p=0;
	for(int i=0;i<m;i++){
		if(ans==(r[x[i]-1]+c[y[i]-1])){
			p++;
		}
	}
	int cnt=0,cnt1=0;
	for(int i=0;i<h;i++){
		if(r[i]==mx){
			cnt++;
		}
	}
	for(int i=0;i<w;i++){
		if(c[i]==mx1){
			cnt1++;
		}
	}
	long long ll=(long long)cnt*cnt1;
	if(ll>p){
		cout<<ans;
	}
	else{
		cout<<ans-1;
	}


	return 0;
} 