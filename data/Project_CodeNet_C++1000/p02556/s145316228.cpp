#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int maxn=1e6;

typedef long long ll;

int a[maxn],b[maxn];

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		a[i]=x+y;b[i]=x-y;
	}
	sort(a,a+n);
    sort(b,b+n);
    int ans=max(a[n-1]-a[0],b[n-1]-b[0]);
    cout<<ans;
	return 0;
}