#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e6+10;
int b[N],r[N];
bool a[N];
int t;
inline int gcd(int x,int y){
	if(!y)
		return x;
	if(x<y)
		swap(x,y);
	return gcd(y,x%y);
}
inline void fj(int x){
	for(int i=1;x!=1&&i<=t;i++)
		if(!a[x]){
			b[x]++;
			return ;
		}
		else if(x%r[i]==0){
			if(x%r[i]==0)
				b[r[i]]++;
			while(x%r[i]==0)
				x/=r[i];
		}
}
int main(){
	a[0]=a[1]=true;
	for(int i=2;i<N;i++)
		if(!a[i]){
			r[++t]=i;
			for(int j=2;j*i<N;j++)
				a[i*j]=true;
		}
	int n;
	cin>>n;
	int x;
	scanf("%d",&x);
	fj(x);
	int k=x;
	for(int i=1;i<n;i++){
		scanf("%d",&x);
		fj(x);
		k=gcd(k,x);
	}
	if(k!=1){
		cout<<"not coprime\n";
		return 0;
	}
	for(int i=1;i<=t;i++)
		if(b[r[i]]>1){
			cout<<"setwise coprime\n";
			return 0;
		}
	cout<<"pairwise coprime\n";
}
