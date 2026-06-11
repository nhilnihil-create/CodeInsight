#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,x,d,c=1,s=0;
 	int ans=INT_MAX;
 	cin>>n;
 	int a[n],b[n];
 	for(i=0;i<n;i++)
 		cin>>a[i];
 	 for(int t = 0; t < n - 1; t++)
	   {
			int s1 = 0, s2 = 0;
			for (int i = 0; i < n; i++)
			 {
				if (i <= t) 
					s1 += a[i];
				else
					 s2 += a[i];
			}
		ans = min(ans, abs(s1 - s2));
		}
 	cout<<ans<<endl;
 	}