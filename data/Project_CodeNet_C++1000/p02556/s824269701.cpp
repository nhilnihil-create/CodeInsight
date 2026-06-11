#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int N=1e6+10;
int a[N],b[N],n,ans;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		a[i] = x+y;b[i]=x-y;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	ans = max(a[n]-a[1],b[n]-b[1]);
	cout<<ans<<'\n';
}