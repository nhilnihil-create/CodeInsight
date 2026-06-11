#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define Check system("pause")
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)



int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int b=s.length();
	if(b%2!=0) cout<<"No";
	else
	{
		for(int i=0;i<b;i+=2)
		{
			if(s[i]!='h' || s[i+1]!='i')
			{
				cout<<"No";
				return 0;
			}		
		}
		cout<<"Yes";
	}
	return 0;
}


