#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define oo 10000000  //1e7
#define f first 
#define s second 

using namespace std;

int p[oo];
 
int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	for(int i=1;i<oo;i++){
		for(int j=i;j*i<oo;j++){
			if(i!=j)p[i*j]+=2;
			else p[i*j]++;
		}
	}

	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<n;i++){
		ans += p[i];
	}
	cout<<ans<<endl;

	return 0;
}
