#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+7;
int a[N];
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int s,n;
	cin>>s>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==1||n==0){
		cout<<0<<endl;
		return 0;
	}
	int maxl = 0;
	for(int i=1;i<n;i++){
		maxl = max(maxl,a[i]-a[i-1]);
	}
	maxl = max(maxl,a[0]+s-a[n-1]);
	cout<<s - maxl<<endl;
}