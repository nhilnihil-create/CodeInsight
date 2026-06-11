#include<bits/stdc++.h>
using namespace std;                                                            
#define pb push_back                                                            
#define mp make_pair                                                                                                                                
#define sqr(a) ((a) * (a))                                                      
#define io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
#define co() cout.precision(10);                                                
#define F for(li i=0;i<n;i++)
#define fo(i,a,n) for(i=a;i<n;i++)
#define ne cout<<"\n"; 
#define test int t;cin>>t;while(t--)
//#define oj #ifndef ONLINE_JUDGE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); #endif

typedef long long li;
typedef long double ld;

const li mod = 1000000007;

int main()
{
	string p,t;
	cin>>p>>t;
	li n=t.length(),i,ans=0;
	fo(i,0,n)
	{
		if(t[i]==p[i])
		ans++;
	}
	cout<<ans;
}