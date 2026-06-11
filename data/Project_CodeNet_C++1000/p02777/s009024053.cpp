#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define ll long long
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug cout<<"Debugging.."<<endl
using namespace std;
int main()
{
	faster;
	map<string,int> m;
	
	string a,b;
	cin>>a>>b;
	
	int c,d;
	cin>>c>>d;
	m[a]=c,m[b]=d;
	string p;
	cin>>p;
	if(m.find(p)!=m.end())
	m[p]--;
	
	cout<<m[a]<<" "<<m[b];	
}


