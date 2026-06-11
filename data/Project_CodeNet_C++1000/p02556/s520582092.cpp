#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int c1[2] = {-1,-1};
	int c2[2] = {-1,-1};
	int c3[2] = {-1,-1};
	int c4[2] = {-1,-1}; 
	
	int l[n],r[n];
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
		
		if(c1[0]==-1 || (l[i]+r[i]<c1[0]+c1[1]))
		{
			c1[0]=l[i];
			c1[1]=r[i];
		}
		
		if(c2[0]==-1 || (-l[i]+r[i]<-c2[0]+c2[1]))
		{
			c2[0]=l[i];
			c2[1]=r[i];
		}
		
		if(c3[0]==-1 || (l[i]-r[i]<c3[0]-c3[1]))
		{
			c3[0]=l[i];
			c3[1]=r[i];
		}
		
		if(c4[0]==-1 || (l[i]+r[i]>c4[0]+c4[1]))
		{
			c4[0]=l[i];
			c4[1]=r[i];
		}
	}
	
	int mx_dist=0;
	
	for(int i=0;i<n;i++)
	{
		mx_dist=max(mx_dist,abs(l[i]-c1[0]) + abs(r[i]-c1[1]));	
		mx_dist=max(mx_dist,abs(l[i]-c2[0]) + abs(r[i]-c2[1]));	
		mx_dist=max(mx_dist,abs(l[i]-c3[0]) + abs(r[i]-c3[1]));	
		mx_dist=max(mx_dist,abs(l[i]-c4[0]) + abs(r[i]-c4[1]));	
	}
	
	cout<<mx_dist<<endl;
	
	return 0;
}