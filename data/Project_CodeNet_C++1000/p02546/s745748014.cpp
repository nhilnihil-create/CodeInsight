#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod  998244353
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define NEG_INF -2e18
			 
const ll INF=1e15;	
const int N=2e5+50;
		 
 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(0);
		
	string s;
	cin>>s;
	int n=s.length();
	
	if(s[n-1]=='s')
	{
		s+="es";
	}
	else
		s+="s";
	cout<<s;
}
