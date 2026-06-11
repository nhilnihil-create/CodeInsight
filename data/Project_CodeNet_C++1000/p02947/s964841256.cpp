
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
using namespace std;
int main()
{
	lli t,n,i,ans=0;
	cin>>n;
	map<string,lli>m;
	string s[n];
	for(i=0;i<n;i++){
		cin>>s[i];
		sort all(s[i]);
		m[s[i]]++;
	}
	map<string,lli>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		t=it->second;
		if(t>1){
			t--;
			ans+=(t*(t+1))/2;
		}		
	}
	cout<<ans;	
	return 0;
}