#include<bits/stdc++.h>
#define ull unsigned long long
#define pi acos(-1)
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
const ll maxn = 1e7+5;
const ll mod = 1e9+7;
int p[10],q[10],a[10];
int main(){
	int n,k=0,x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[i]=p[i];
	}
	for(int i=1;i<=n;i++) cin>>q[i]; 
	sort(p+1,p+n+1);
	do{
		k++;
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==p[i]) flag1++;
			if(q[i]==p[i]) flag2++;
			//cout<<p[i]<<" ";
		}
		if(flag1==n) x=k;
		if(flag2==n) y=k;
		//cout<<'\n';
	}while(next_permutation(p+1,p+n+1));
	cout<<abs(x-y)<<'\n';
	return 0;
}
