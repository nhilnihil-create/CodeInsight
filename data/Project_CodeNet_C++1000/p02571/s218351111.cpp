#include<bits/stdc++.h>                                                   //---------------------------------------------------------------

# define ll long long
# define mod 1000000007
# define MAX 100005
# define PI 3.141592653589793238                                                                                  //shortcut keys

# define pb push_back
# define mp make_pair
# define all(x) x.begin(),x.end()
# define fr(i,a,b) for(int i=a;i<=b;i++)

# define decimal(k) fixed<<setprecision(k)
# define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);        //---------------------------------------------------------------
using namespace std;

int main()
{
	
	string s,t;cin>>s>>t;
	int n=s.size(),m=t.size();
	int ans=INT_MAX;
	for(int i=0;i<n-m+1;i++){
		string a=s.substr(i,m);
		int cnt=0;
		fr(i,0,m-1){
			if(a[i]!=t[i])cnt++;
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<'\n';

	return 0;
}

