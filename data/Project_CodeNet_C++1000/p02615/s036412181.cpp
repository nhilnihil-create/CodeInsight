#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
int main(){
	int n;
	cin>>n;
	int a[n];
	rep(i,n)cin>>a[i];
	sort(a,a+n);
	ll sum=0;
	sum+=a[n-1];
	int j=2,count=2;
	while(1){
		if(j>=n)break;
		sum+=a[n-count];
		j++;
		if(j>=n)break;
		sum+=a[n-count];
		j++;
		if(j>=n)break;
		count++;
	}
	cout << sum;
	return 0;
}