#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	int n;cin>>n;
	string s;cin>>s;
	for(int i=0;i<s.length();i++)
	{
		cout<<(char)((s[i]-'A'+n)%26+65);
	}
}