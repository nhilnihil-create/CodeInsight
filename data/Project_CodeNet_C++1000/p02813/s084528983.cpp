#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100],b[100],tr[100],ra[100];
int lowbit(int x){
	return x&-x;
}
void add(int pos,int c,int n){
	while(pos<=n){
		tr[pos]+=c;
		pos+=lowbit(pos);
	}
}
int getsum(int n){
	int ret=0;
	while(n){
		ret+=tr[n];
		n-=lowbit(n);
	}
	return ret;
}
int kt(int a[],int n){
	int ret=0;
	for(int i=n;i>=1;i--){
		ret+=ra[n-i]*getsum(a[i]-1);
		add(a[i],1,n);
	}
	return ret;
} 
void init(int n){
	ra[0]=1;
	for(int i=1;i<=n;i++) ra[i]=i*ra[i-1];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	init(30);
	int num1=kt(a,n);
	memset(tr,0,sizeof tr);
	int num2=kt(b,n);
	cout<<abs(num1-num2)<<'\n';
	return 0;
 } 