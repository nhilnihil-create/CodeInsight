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

//long long a[99999999];
//long long b[99999999];

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0), cout.tie(0);

ll n;
cin>>n;
ll k,ans=0;
for(int i=1;i<=n;i++)
{
	k=n/i;
	ans+=i*k*(k+1) / 2;
}

cout<<ans<<"\n";











	
	
	return 0;
	
	
	       /***Israil Hosen
	            Computer Science & Engineering
	         University Of Rajshahi.
	         ***/
	
	
	
}