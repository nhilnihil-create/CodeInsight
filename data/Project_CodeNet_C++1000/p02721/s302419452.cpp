#include<bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define fi first
#define se second
using namespace std;
template <class T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <class T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;

int n,k,c;
string s;
vector<int> b,e;

int main()
{
	cin>>n>>k>>c>>s;
	c++;
	int day=0,i=1;
	b.pb(-inf);
	while(true)
	{
		while(day<sz(s)&&(s[day]=='x'||day-b.back()<c)) day++;
		if(day>=sz(s)) return 0;
		b.pb(day);
		i++;
		if(i>k) break;
		day++;
	}
	e.pb(inf);
	day=sz(s)-1,i=1;
	while(true)
	{
		while(day<sz(s)&&(s[day]=='x'||e.back()-day<c)) day--;
		if(day>=sz(s)) return 0;
		e.pb(day);
		i++;
		if(i>k) break;
		day--;
	}
	reverse(all(e));
	e.pop_back();
	b.erase(b.begin());
	for(int i=0;i<k;i++)
		if(b[i]==e[i])
			cout<<b[i]+1<<endl;
	return 0;
}