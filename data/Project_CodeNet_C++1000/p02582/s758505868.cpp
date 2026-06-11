#include<bits/stdc++.h>
#define SPEED ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long int
#define inf 999999999
#define maxn 200003
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7;
using namespace std;
void code()
{
	string s;
	cin >> s;
	int rcount = 0, scount =0 ;
	for(auto i: s)
	{
		if(i=='S')
		{
			scount++;
		}
		else
		{
			rcount++;
		}
	}
	if(rcount==3)
	{
		cout << "3";
	}
	if(scount==3)
	{
		cout<<"0";
	}
	if(rcount==2)
	{
		if(s[1]=='S')
		{
			cout << "1";
		}
		else
		{
			cout << "2";
		}
	}
	if(rcount==1)
	{
		cout << "1";
	}
}
int main()
{
	SPEED
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.out","w",stdout);
	#endif
	int t = 1;
	while(t--)
	{
		code();//DEBUG
	}
}