#include<bits/stdc++.h>
using namespace std;
const int N=19,MAX=1e9;
int a[1<<N];
struct Treap
{
	struct Node
	{
		int key;
		int pr;
		int ma;
		int sz;
		int br;
		Node *l;
		Node *r;
		Node(int kkey)
		{
			key=kkey;
			pr=rand();
			ma=kkey;
			l=r=NULL;
			sz=1;
			br=1;
		}
		void con()//Keeps everything updated during splits and merges
		{
			ma=key;
			sz=br;
			if(l)
			{
				ma=max(ma,l->ma);
				sz+=l->sz;
			}
			if(r)
			{
				ma=max(ma,r->ma);
				sz+=r->sz;
			}
		}
		void output()//Outputs the keys in the treap in ascending order
		{
			if(l)l->output();
			cout<<key<<endl;
			if(r)r->output();
		}
	};
	Node *node;
	Treap()
	{
		node=NULL;
	}
	void split(Node *T,Node *&L,Node *&R,int key)//splits T into L and R where all the keys of L are <=key and all the keys of R are >key
	{
		if(!T)
		{
			L=R=NULL;
			return;
		}
		if(T->key <= key)
		{
			L=T;
			split(T->r,L->r,R,key);
		}
		else
		{
			R=T;
			split(T->l,L,R->l,key);
		}
		T->con();
	}
	void split_sz(Node *T,Node *&L,Node *&R,int x)//splits T into L and R where L contains the first x elemets ot T and R has everything else
	{
		if(!T)
		{
			L=R=NULL;
			return;
		}
		int size=1;
		if(T->l)size+=T->l->sz;
		if(size <= x)
		{
			L=T;
			split_sz(T->r,L->r,R,x-size);
		}
		else
		{
			R=T;
			split_sz(T->l,L,R->l,x);
		}
		T->con();
	}
	void merge(Node *&T,Node *L,Node *R)//merges L and R into T where all keys of L are <= of all keys in R
	{
		if(!L)
		{
			T=R;
			return;
		}
		if(!R)
		{
			T=L;
			return;
		}
		if(L->pr > R->pr)
		{
			T=L;
			merge(T->r,L->r,R);
		}
		else
		{
			T=R;
			merge(T->l,L,R->l);
		}
		T->con();
	}
	void insert(int key)//inserts an element into the treap
	{
		Node *L,*MID,*R;
		split(node,L,R,key);
		split(L,L,MID,key-1);
		if(MID)
		{
			MID->br+=1;
			MID->sz+=1;
		}
		else MID=new Node(key);
		merge(L,L,MID);
		merge(node,L,R);
	}
	void erase(int x)
	{
		Node *L,*MID,*R;
		split(node,L,R,x);
		split(L,L,MID,x-1);
		MID->br--;
		if(MID->br!=0)merge(L,L,MID);
		merge(node,L,R);
	}
	int query(int x)//answer the qurty how many numbers <=x are in the trap
	{
		Node *L,*R;
		split(node,L,R,x-1);
		int ans=-1;
		if(L)ans=L->ma;
		merge(node,L,R);
		return ans;
	}
}T;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,b,i,j;
	cin>>n;
	for(i=0;i<(1<<n);i++)
	{
		cin>>b;
		T.insert(b);
	}
	int m=1;
	a[0]=T.query(MAX+1);
	T.erase(a[0]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[j+m]=T.query(a[j]);
			if(a[j+m]==-1)
			{
				cout<<"No\n";
				return 0;
			}
			T.erase(a[j+m]);
		}
		m*=2;
	}
	cout<<"Yes\n";
}
