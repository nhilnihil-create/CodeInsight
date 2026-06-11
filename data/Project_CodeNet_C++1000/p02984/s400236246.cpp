#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
  	cin>>n;
  	vector<int>A(n);
  	for(int i=0;i<n;i++)cin>>A[i];
  	
  	vector<long long>a(n);
  	a[0]=0;
  	for(int i=1;i<n;i++)a[i]=(long long)2*(A[i-1]-(a[i-1]/2));
  	long long x=A[n-1]-(a[n-1])/2;
  	int flag=1;
  	for(int i=0;i<n;i++)
    {
      cout<<(long long)a[i]+(flag*x)<<" ";
      flag*=-1;
    }
 	return 0;
}