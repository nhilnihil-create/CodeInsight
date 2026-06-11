#include <iostream>
#include <algorithm>
using namespace std;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int n;
int a[100001];

int main(){
	cin.tie(0);
	
	cin>>n;
	rep(i, n)cin>>a[i];
	
	sort(a, a+n);
	
	cout<<a[0]<<' '<<a[n-1]<<' ';
	
	long long s = 0;
	rep(i, n)s += a[i];
	
	cout<<s<<endl;
	
	return 0;
}

