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
	int n;
	cin >> n;
	int l[n];
	for(int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	int cnt = 0;
	for(int i = 0; i < n-2; i++)
	{
		for(int j = i+1; j < n-1; j++)
		{	
			for(int k = j+1; k < n; k++)
			{
				if(!((l[i]==l[j]) || (l[j]==l[k]) || (l[k]==l[i])))
				{
					if((l[i]+l[j] > l[k]) && (l[j]+l[k] > l[i])&&(l[i]+l[k] > l[j]))
					{

//					cout << l[i] << " " << l[j] << " " << l[k] << "\n";
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt;
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