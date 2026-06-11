#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw	 "\n"
#define mod 1000000007


int main(void)
{
	CIN;
	ll tc,l,k=0,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	cin>>tc;
	db la=0;
	int arr[tc][2];
	for(int i=0;i<tc;i++)
			cin>>arr[i][0]>>arr[i][1];

	for(int i=0;i<tc-1;i++){
		for(int j=i+1;j<tc;j++){
			db p=(arr[i][0]-arr[j][0])*(arr[i][0]-arr[j][0]);
			db q=(arr[i][1]-arr[j][1])*(arr[i][1]-arr[j][1]);
			
			la+=sqrt(p+q);
			cnt++;
		}
	}
	printf("%.10f\n",la*(tc-1)/cnt );
}