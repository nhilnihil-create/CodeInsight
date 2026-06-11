#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>  
#include<set>
#include<iterator>
#include<list>
#include<utility>
#include<cstdlib>
#include<queue>
#include<stack>
#include<bitset>
//#include<bits/stdc++.h>
#define PI  2*acos(0.0)
#define pb push_back

       
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;



int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0), cout.tie(0);

ll n;
cin>>n;
ll a[n];
for(int i=0;i<n;i++)  cin>>a[i];

ll cnt=0;
sort(a,a+n);
for(int i=0;i<n-2;i++)
{
	for(int j=i+1;j<n-1;j++)
	{
		for(int k=j+1;k<n;k++)
		{
			if(a[i]+a[j]>a[k] && a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] )
			{
				cnt++;
			}
			
		}
		
	}
	
}


cout<<cnt<<"\n";


	
	
	return 0;
	
	
	       /***Israil Hosen
	            Computer Science & Engineering
	         University Of Rajshahi.
	         ***/
	
	
	
}