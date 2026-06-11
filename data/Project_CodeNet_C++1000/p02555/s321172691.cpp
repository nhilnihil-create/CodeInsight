
#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,a,n) for(i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define vsz v.size()
#define pi 3.141592653589793238
#define mod 1000000007
using namespace std;
int main()
{
	lli t,n,s,j,i;
	cin>>s;
	vector<lli>ds(2001,1);
	ds[0]=ds[1]=ds[2]=0;
	for(i=3;i<=s;i++){
		j=i-3;
		while(j>=3){
			ds[i]+=ds[j];
			ds[i]%=mod;
			j--;
		}
	}
	cout<<ds[s];	
	return 0;
}