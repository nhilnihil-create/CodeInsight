#include<bits/stdc++.h>
using namespace std;
typedef long long int lli; 
string s;
lli a,b,c,t,temp1,temp2,x,y,temp,q,d,k,mod=1e9+7;

bool is(int i,int j)
{
	string one="",two="";
	
	for(int a=i;a<=j;a++)
	{
		one+=s[a];
		two+=s[a];
	}
	
	reverse(two.begin(),two.end());

	if(one==two)return true;
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin>>s;
	lli len=s.length();
	s="0"+s;
	
	if(is(1,len)&&is(1,(len-1)/2)&&is((len+3)/2,len))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
