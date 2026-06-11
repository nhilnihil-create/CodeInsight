#include <bits/stdc++.h>
     
#define pll pair <long long,long long>
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define vll vector <ll>
#define NFS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define endl '\n'
#define M 1000000007   
using namespace std;
 
void solve()
{
	int k;
	string s,g="";
	cin>>k;
	cin>>s;
	for(int i=0;i<min(k,(int)s.length());i++)
	{
		g+=s[i];
	}
	if((int)s.length()>k)
		g+="...";
	cout<<g;
}
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    NFS
 	int t=1;
 	//cin>>t;
 	while(t--)
 	{
 		solve();
 	}
    return 0;
}