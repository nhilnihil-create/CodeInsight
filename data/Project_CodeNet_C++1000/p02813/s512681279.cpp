#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(int i=0;i<(int)v.size();i++) cout<<" "<<v[i]; cout<<endl;
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p[n];
		int q[n];
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin>>p[i];
			a[i]=i+1;
		}
		for (int i = 0; i < n; i++)
		{
			cin>>q[i];
		}
		int i=1,c,b;
		do{
			int f=0,g=0;
			for(int i=0;i<n;i++){
				if(a[i]!=p[i])
					f=1;
			}
			for(int i=0;i<n;i++){
				if(a[i]!=q[i])
					g=1;
			}
			if(!f)
				c=i;
			if(!g)
				b=i;
			i++;
		}while (next_permutation(a,a+n));
		cout<<abs(c-b)<<endl; 
	}
}

