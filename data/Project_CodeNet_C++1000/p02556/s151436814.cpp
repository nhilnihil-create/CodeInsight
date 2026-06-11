#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;

int main()
{
	int n;cin>>n;
	vector<ll> a,b;
	for(int i=1;i<=n;i++){
		ll x,y;cin>>x>>y;
		a.push_back(x+y);b.push_back(x-y);
	}
	sort(a.begin(),a.end());sort(b.begin(),b.end());
	cout<<max(a[n-1]-a[0],b[n-1]-b[0]);
	return 0;	
} 