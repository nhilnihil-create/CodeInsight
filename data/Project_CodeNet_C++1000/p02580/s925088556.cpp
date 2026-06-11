#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll,ll> pii;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rept(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define all(x) x.begin(),x.end()
#define pb push_back
#define fi first
#define se second
#define mes(a,b) memset(a,b,sizeof a)
#define mp make_pair
#define dd(x) cout<<#x<<"="<<x<<" "
#define de(x) cout<<#x<<"="<<x<<"\n"
#define debug() cout<<"I love Miyamizu Mitsuha forever.\n"
const int inf=0x3f3f3f3f;
const int maxn=3e5+5;

vector<int> v[maxn];
int cnt[maxn];

class element
{
	public:
		int l,r;
		int plus,val;
};

class Tree
{
	public:
		element tree[maxn<<2];
		void build(int id,int l,int r)
		{
			tree[id].l=l;
			tree[id].r=r;
			tree[id].plus=0;
			if(l==r)
			{
				tree[id].val=cnt[l];
				return ;
			}
			int mid=(l+r)/2;
			build(id*2,l,mid);
			build(id*2+1,mid+1,r);
			tree[id].val=max(tree[id*2].val,tree[id*2+1].val);
		}
		void add(int id,int l,int r,ll num)
		{
			if(tree[id].l>=l&&tree[id].r<=r)
			{
				tree[id].plus+=num;
				tree[id].val+=num;
				return ;
			}
			if(tree[id].l>r||tree[id].r<l) return ;
			push_down(id);
			if(tree[id*2].r>=l) add(id*2,l,r,num);
			if(tree[id*2+1].l<=r) add(id*2+1,l,r,num);
			tree[id].val=max(tree[id*2].val,tree[id*2+1].val);
		}
		void push_down(int id)
		{
			if(tree[id].l!=tree[id].r)
				rept(j,id*2,id*2+1)
				{
					tree[j].val+=tree[id].plus;
					tree[j].plus+=tree[id].plus;
				}
			tree[id].plus=0;
		}
		ll query(int id,int l,int r)
		{
			if(tree[id].l>=l&&tree[id].r<=r) return tree[id].val;
			if(tree[id].l>r||tree[id].r<l) return -inf;
			push_down(id);
			return max(query(id*2,l,r),query(id*2+1,l,r));
		}
} t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,0,k)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		cnt[y]++;
	}
	t.build(1,1,m);
	int ans=0;
	rept(i,1,n)
	{
		rep(j,0,v[i].size()) t.add(1,v[i][j],v[i][j],-1);
		ans=max(ans,t.tree[1].val+(int)v[i].size());
		rep(j,0,v[i].size()) t.add(1,v[i][j],v[i][j],1);
	}
	cout<<ans<<"\n";
}