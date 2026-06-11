#include<cstdio>
#include<cstring>
#define N 4000001
#define y1 ysfhfauhsud
#define MAX 400001
using namespace std;
int total1,ans;
int head[N],next[N],edge[N],x1[N],y1[N],x[N],y[N],fmax[N],p1[N],p2[N];
int n,m,k;
void swap(int &x,int &y)
{
	int t=x;x=y;y=t;
}
void insert(int x,int y)
{
	total1++;
	next[total1]=head[x];
	head[x]=total1;
	edge[total1]=y;
}
void qsort1(int l,int r)
{
	int i=l,j=r;
	int mid=x1[(i+j)/2];
	while (i<=j)
	{
		while (x1[i]<mid) i++;
		while (x1[j]>mid) j--;
		if (i<=j)
		{
			swap(x1[i],x1[j]);
			i++;j--;
		}
	}
	if (i<r) qsort1(i,r);
	if (l<j) qsort1(l,j);
}
void qsort2(int l,int r)
{
	int i=l,j=r;
	int mid=y[(i+j)/2];
	while (i<=j)
	{
		while (y[i]<mid) i++;
		while (y[j]>mid) j--;
		if (i<=j)
		{
			swap(y[i],y[j]);
			swap(x[i],x[j]);
			i++;j--;
		}
	}
	if (i<r) qsort2(i,r);
	if (l<j) qsort2(l,j);
}
int max(int x,int y)
{
	if (x<y) return y;
	return x;
}
void maketree(int ma,int l,int r)
{
	if (l==r)
	{
		fmax[ma]=p2[l];
		return;
	}
	int mid=(l+r)/2;
	maketree(ma*2,l,mid);
	maketree(ma*2+1,mid+1,r);
	fmax[ma]=max(fmax[ma*2],fmax[ma*2+1]);
}
int find_ans(int ma,int l,int r,int l1,int r1)
{
	if (l1>r1) return 0;
	if (l==l1&&r==r1) return fmax[ma];
	int mid=(l+r)/2;
	if (r1<=mid) return find_ans(ma*2,l,mid,l1,r1);
	if (mid<l1) return find_ans(ma*2+1,mid+1,r,l1,r1);
	int s=find_ans(ma*2,l,mid,l1,mid);
	s=max(s,find_ans(ma*2+1,mid+1,r,mid+1,r1));
	return s;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		//p[y[i]]++;
	}
	for (int i=1;i<=k;i++)
		x1[i]=x[i];
	qsort1(1,k);
	qsort2(1,k);
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	for (int i=k;i>=1;i--)
	{
		p2[y[i]]++;
		p1[x[i]]++;
		insert(x[i],i);
	}
	maketree(1,1,MAX);
	ans=0;
	for (int i=1;i<=k;i++)
	{
		if (i!=k&&x1[i]==x1[i-1]) continue;
		int last=1;
		for (int j=head[x1[i]];j;j=next[j])
		{
			int ys1=edge[j];
			ans=max(ans,p2[y[ys1]]+p1[x1[i]]-1);
			ans=max(ans,p1[x1[i]]+find_ans(1,1,MAX,last,y[ys1]-1));
			last=y[ys1]+1;
		}
		ans=max(ans,p1[x1[i]]+find_ans(1,1,MAX,last,MAX));
	}
	printf("%d\n",ans);
}