#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[1005][1005],n,l[1005],f[1005];
int read(){
	int X=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){X=(X<<1)+(X<<3)+ch-'0';ch=getchar();}
	if(flag)return X;
	return ~(X-1);
}
V<int> v,t;
int main(){
    n=read();
    FOR(i,1,n){
    	FOR(j,1,n-1)a[i][j]=read();
    	l[i]=1;v.PB(i);
    }
    int ans=0;
    while(1){
    	bool anf=0;
    	for(int i=0;i<v.size();i++){
    		if(l[v[i]]<n){
    			anf=1;break;
    		}
    	}
    	if(!anf)break;
		ans++;
		anf=0;t.clear();
    	for(int j=0;j<v.size();j++){
    		int i=v[j];
    		if(l[i]>=n||l[a[i][l[i]]]>=n)continue;
    		if(f[i]||f[a[i][l[i]]])continue;
    		if(a[a[i][l[i]]][l[a[i][l[i]]]]==i){
    			anf=1;
    			t.PB(i);t.PB(a[i][l[i]]);f[i]=1;f[a[i][l[i]]]=1;
    			l[a[i][l[i]]]++;l[i]++;
    		}
    	}
    	for(int j=0;j<t.size();j++)f[t[j]]=0;
    	v=t;
    	if(!anf){
    		puts("-1");return 0;
		}
//    	FOR(i,1,n)cout<<l[i]<<' ';
//    	cout<<'\n';
    }
    printf("%d",ans);
	RE 0;
}
