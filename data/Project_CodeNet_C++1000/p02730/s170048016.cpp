#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
#define inf 1000000000
#define mod 1000000007
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;

string s;

int f(string str)
{
	for(int i=0;i<sz(str);i++)
	{
		int j=sz(str)-i-1;
		if(str[i]!=str[j]) return 0;
	}
	return 1;
}

int main()
{
	cin>>s;
	int n=sz(s);
	s=" "+s;
	if(f(s.substr(1,n))&&f(s.substr(1,(n-1)/2))&&f(s.substr((n+3)/2,n-(n+3)/2+1))) 
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}