#include<bits/stdc++.h>
#define ft(i,l,r) for(register int i=l;i<=r;i++)
#define fd(i,r,l) for(register int i=r;i>=l;i--)
using namespace std;
int n,a[114514],b[114514];
void qsort(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(mid<a[j]) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;j--;
		}
	 } 
	if(i<r) qsort(i,r);
	if(l<j) qsort(l,j);
}
int main()
{
	cin>>n;
	ft(i,1,n) {scanf("%d",&a[i]);b[i]=i;}
	qsort(1,n);
	ft(i,1,n) printf("%d ",b[i]);
	return 0;
}