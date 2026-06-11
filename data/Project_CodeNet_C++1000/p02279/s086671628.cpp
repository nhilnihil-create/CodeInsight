#include <bits/stdc++.h>
#define inf (1<<29)
#define sq(n) ((n)*(n))
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define MEMSET(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
using ll = long long;

#define MAX 100005
#define NIL -1

struct node{int p,l,r;};
node t[MAX];
int n,d[MAX];

void print(int u){
	cout<<"node "<<u<<": ";
	cout<<"parent = "<<t[u].p<<", ";
	cout<<"depth = "<<d[u]<<", ";
	if(t[u].p==NIL)cout<<"root, ";
	else if(t[u].l==NIL)cout<<"leaf, ";
	else cout<<"internal node, ";
	cout<<"[";
	int i,c;
	for(i=0,c=t[u].l;c!=NIL;i++,c=t[c].r){
		if(i)cout<<", ";
		cout<<c;
	}
	cout<<"]"<<endl;
}

void dep(int u,int p){
	d[u]=p;
	if(t[u].r!=NIL)dep(t[u].r,p);
	if(t[u].l!=NIL)dep(t[u].l,p+1);
}

signed main(){
	cin>>n;
	rep(i,n)t[i].p=t[i].l=t[i].r=NIL;
	rep(i,n){
		int id,k,c;
		cin>>id>>k;
		int l;
		rep(j,k){
			cin>>c;
			if(j)t[l].r=c;
			else t[id].l=c;
			t[c].p=id;
			l=c;
		}
	}
    int r;
	rep(i,n)if(t[i].p==NIL)r=i;
	dep(r,0);
	rep(i,n)print(i);
	return 0;
}
