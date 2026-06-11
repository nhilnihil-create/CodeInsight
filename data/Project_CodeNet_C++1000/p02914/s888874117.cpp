#include <bits/stdc++.h>
#define ll long long
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn = 1e5 + 10;

int n;
ll a[maxn];
int zero[64], tot;
ll p[64];

void insert(ll x){
	for(int i=0;i<tot;i++){
		if((x>>zero[i])&1){  
			if(!p[i]){
				p[i] = x;
				break;
			}else{
				x^=p[i];
			}
		}
	}
}

int main()
{   
	read(n);
	ll sum = 0;
	tot = 0;
	for(int i=0;i<n;i++) cin>>a[i],sum^=a[i];
	for(int i=60;i>=0;i--) 
		if(!((sum>>i)&1)) zero[tot++] = i;
	for(int i=0;i<n;i++) insert(a[i]);  //构造线性基
	ll res = 0;
	for(int i=0;i<tot;i++){
		if(!((res>>zero[i])&1)) res ^= p[i];
 	}
	cout<<(sum^res)+res<<endl;
	return 0;
}