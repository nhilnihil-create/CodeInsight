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

	string a,b;
	cin>>a>>b;
	int flag=0;
	for(char c='a';c<='z';c++)
	{
		if(a+c==b)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)cout<<"No";
	else
	cout<<"Yes";
		

}


