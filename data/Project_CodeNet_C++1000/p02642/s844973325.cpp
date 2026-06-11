#include <bits/stdc++.h>
 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fff(i,a,b) for(int (i)=(a);(i)<=(b);i++)
#define pb push_back
#define len(a) (a).length()
#define all(a) (a).begin(),(a).end()
#define sz(a) (a).size()
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long ,long long > pll;
typedef unsigned long long ull;
typedef long double ld;
 
const int mn=1e6+69;
int kolko[mn];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t=1;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int num=0;
	for(int i=0;i<n;i++) kolko[a[i]]=0;
	for(int i=0;i<n;i++) kolko[a[i]]++;
	for(int i=0;i<n;i++)
	{
		bool sta=true;
		for(int j=1;j*j<=a[i];j++)
		{ 
			if(a[i]%j==0)
			{
				if(j!=a[i] && kolko[j]>0) sta=false;
				else if(j==a[i] && kolko[j]>1) sta=false;
				int pom=a[i]/j;
				if(pom!=a[i] && kolko[pom]>0) sta=false;
				else if(pom==a[i] && kolko[pom]>1) sta=false;
			}
		}
		if(sta) num++;
	}
	cout<<num<<endl;
	return 0;
}