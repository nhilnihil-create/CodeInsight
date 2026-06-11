//in dp prefix suffix sum helps..
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stack>
#include <iterator>
#include <map>
#include<list>
#include <fstream>
#include<unordered_map>
#include<set>
#include<queue>
#define int long long
#define double long double
#define pb   push_back
#define mp   make_pair
#define pii  pair<int,int>
#define pip vector<pair<int, pair<int, int> > >
#define viv vector<vector<int> >
#define vip vector<pair<int, int> >
#define vi vector<int>
#define mii  map<pair<int, int>, int>
#define li list<int>
#define qu queue<int>
#define set set<int>
#define stack stack<int>
#define fi first
#define se second
#define mem(x, y) memset(x, y, sizeof(x))
#define pq priority_queue<int>
#define pq1 priority_queue <int, vector<int>, greater<int> >
#define ps(x,y) fixed<<setprecision(y)<<x
// author :: Anurag Anand.
using namespace std;
int z= 1000000007;
//int z= 998244353;
int gcd(int a, int b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b, a%b);
}
int power(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=(res*a)%z;
			b--;
		}
		else
		{
			a=(a*a)%z;
			b=b>>1;
		}
	}
	return res;
}
vi seg;
void arrange(int i, int v, int x, int lx, int rx){
	if(rx-lx==1){
		seg[x]+=v;
		return;
	}
	int mid= lx+(rx-lx)/2;
	if(i<mid) arrange(i, v, 2*x+1, lx, mid);
	else arrange(i, v, 2*x+2, mid, rx);
	seg[x]= seg[2*x+1]+seg[2*x+2];
}
int sum(int l, int r, int x, int lx, int rx){
	if(l>=rx||r<=lx) return 0;
	if(lx>=l&&rx<=r) return seg[x];
	int mid=(lx+rx)/2;
	int sl= sum(l, r, 2*x+1, lx, mid), sr= sum(l, r, 2*x+2, mid, rx);
	return (sl+sr);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	int t;
	t=1;
	//cin>>t;
	while(t--){
		string s;
		cin>>s;
		int l= s.length();
		if(s[l-1]=='s'){
			s+='e';
			s+='s';
		}
		else s+='s';
		cout<<s<<"\n";
	}
}