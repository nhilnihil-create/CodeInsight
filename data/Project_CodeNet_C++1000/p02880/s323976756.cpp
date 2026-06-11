//Bismillahir Rahmanir Rahim 
#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define gcd(a,b) __gcd(a,b)
#define endl '\n'
const int N=2e5+10;
const int inf=1e9;
const int mod=1e9+7;

int  main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

	int n;
	cin >> n;

	for(int i=1; i<=9; i++)
	{
		if(n%i==0)
		{
			int a=n/i;

			if(a<=9)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	
	return 0;
}