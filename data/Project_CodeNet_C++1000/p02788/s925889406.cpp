#include<bits/stdc++.h>
#define ll 				long long
#define ld 				long double
#define fastio 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) 		cerr<<#x<<" "<<x<<endl
#define cina(a,n) 		for(ll i = 0;i<n;i++)	cin>>a[i];
#define couta(a,n) 		for(ll i = 0;i<n;i++) cout<<a[i]<<" ";
#define fauto(ar)		for(auto x : ar)	cout<<x<<" ";
#define mod 			1000000007
#define siz 			105
#define f 				first
#define s 				second
#define pb 				push_back
#define endl 			"\n"
#define ci 				cin.ignore()
using namespace std;
struct nodes
{
	ll x,h;
};
bool cmp(nodes a,nodes b)
{
	return a.x < b.x;
}
ll getpos(nodes *node,ll n,ll start,ll value)
{
	ll end = n,mid,pos = start;
	while(start <= end)
	{
		mid = start + end >> 1;
		
		if(node[mid].x <= value)
		{
			pos = mid;
			start  = mid+1;
		}
		else
		end = mid-1;	
	}
	return pos;
	
}
void update(ll *bit,ll n,ll ind,ll value)
{
	for(;ind <= n;ind += ind&-ind)
	bit[ind] += value;
}
ll query(ll *bit,ll ind)
{
	ll res = 0;
	for(;ind >= 1;ind -= ind&-ind)
	res += bit[ind];
	return res;
}
int main()
{
	ll n,d,a,i,j,right;
	cin>>n>>d>>a;
	
	nodes node[n];
	for(i = 0;i<n;i++)
	cin>>node[i].x>>node[i].h;
	
	sort(node,node+n,cmp);
	
	ll bit[n+4];
	memset(bit,0,sizeof(bit));
	
	ll ans = 0,curr;
	for(i = 0;i<n;i++)
	{
		update(bit,n,i+1,node[i].h);
		update(bit,n,i+2,node[i].h*-1);
//		cout<<i+1<<" "<<query(bit,i+1)<<endl;
	}
	for(i = 0;i<n;i++)
	{
		right = getpos(node,n,i,node[i].x+2*d);
		
		curr = query(bit,i+1);
		if(curr < 0)
		curr = 0;
		// get the ans;
		
		
		if(curr%a)
		{
			curr = curr/a;
			curr++;	
		}	
		else
		curr /= a;
		
		ans += curr;
		
		update(bit,n,i+1,curr*-a);
		update(bit,n,right+2,curr*a);
		
//		cerr<<"\n"<<i+1<<" -> ";
//		
//		for(j = 0;j<n;j++)
//		cerr<<query(bit,j+1)<<" ";		
		
	}
	
	cout<<ans;
	
	
	
	
	
}