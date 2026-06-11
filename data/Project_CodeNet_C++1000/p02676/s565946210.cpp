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
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int n;
	cin>>n;
	string s;
	cin>>s;
	if((int)s.length()<=n)
		cout<<s<<endl;
	else{
		for(int i=0;i<n;i++)
			cout<<s[i];
		cout<<"...\n";
	}
}

