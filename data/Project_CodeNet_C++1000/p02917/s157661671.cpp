#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define accum(x) accumulate((x).begin(),(x).end(),0)

int main(){
	int n; cin>>n;
	vector<int> a(n);
	vector<int> b(n-1);
	rep(i,n-1) cin>>b[i];
	a[0]=b[0];
	for(int i=1; i<n; i++){
		a[i]=min(b[i-1],b[i]);
	}
	a[n-1]=b[n-2];
	cout<<accum(a)<<endl;
}