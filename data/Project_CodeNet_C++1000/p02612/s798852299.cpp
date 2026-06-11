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

if(n%1000==0)
{
	cout<<0<<"\n";
}

else
{
	cout<<((n/1000)+1)*1000 - n<<"\n";
}












	
	
	return 0;
	
	
}