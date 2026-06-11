#include<bits/stdc++.h>
using namespace std;

#define mod      1e9+7;
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0;
	for(int i=0;i<k;i++)
		sum+=a[i];
	int best=sum;
	for(int i=k;i<n;i++){
		sum+=a[i]-a[i-k];
		best=max(best,sum);
	}
	best=best+k;  double ans=(double)best/2.00;
	cout<<ps(ans,18)<<endl;
	return 0;
}