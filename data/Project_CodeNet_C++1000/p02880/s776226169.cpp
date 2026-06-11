#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define pi pair<ll,ll>
#define ff first
#define ss second
#define MAX 100005
const ll MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t=1;
//	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
			{
				if(i*j==n)
			    {
			    	cout<<"Yes\n";
			    	return 0;
				}
			}
		}
		cout<<"No\n";
	 
	}		
}