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
	string s;cin>>s;
	int n=s.size();
	ll sum=0;
	fr(i,0,n-1){
		sum+=s[i]-'0';
	}
	if(sum%9==0)cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';

	return 0;
}

