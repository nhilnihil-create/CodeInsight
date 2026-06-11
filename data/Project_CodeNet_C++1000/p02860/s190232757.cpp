#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<time.h>
#include<cstring>
#include<iomanip>
#include<numeric>
#include<list>
#include<stack>
#include<sstream>
#define lli long long int
#define h 100
#define pf push_front
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
using namespace std;
int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL) ;
  lli t, k, i, n, m, sum, flag, j;
  	cin>>n;
  	string x;
  	cin>>x;
  	if(n%2==1)cout<<"No"<<endl;
  	else
  	{
  		flag=1;
  		for(i=0,j=n/2;j<x.size();j++, i++)  
  		if(x[i]!=x[j]) {flag=0;break;} 
  		if(flag) cout<<"Yes"<<endl;
  		else cout<<"No"<<endl;
  	} 
  return 0;
} 
