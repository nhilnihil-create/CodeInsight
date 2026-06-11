#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int d[maxn],f[maxn];
int main(){
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		f[i]=a+b;
		d[i]=a-b;
	}
	sort(f+1,f+1+n);
	sort(d+1,d+1+n);
	ll x=max(f[n]-f[1],d[n]-d[1]);
	cout<<x<<endl;
} 