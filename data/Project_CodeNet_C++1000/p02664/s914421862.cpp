#include<bits/stdc++.h>
#define ll long long int
#define CON 100010
const long long mod=1e9+7;
const int INF=1001001001;
const ll inf=1e9+7;
using namespace std;
int main() 
{
	string s;
	cin>>s;
	string pre("0");
	string aft("0");
	int count=s.size();
	for(int i=0;i<count;i++)
	{
		aft=s[i+1];
		if(s[i]=='?'&&(pre[0]=='P'||aft[0]=='P'||i==count-1))
		{
			s[i]='D';
		}
		if(s[i]=='?'&&(aft[0]=='D'||aft[0]=='?'))
		{
			s[i]='P';
		}
		pre=s[i];
	}
	cout<<s<<endl;
	return 0;
}
