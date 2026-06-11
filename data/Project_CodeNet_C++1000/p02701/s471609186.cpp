#include<bits/stdc++.h>
#define mod 1000000007
#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) (v).size()
using namespace std;
template <typename T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <typename T> void chmin(T &x,T y){x=x<y?x:y;return;}

int n;
set<string> s;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		s.insert(str);
	}
	cout<<sz(s)<<endl;
	return 0;
}