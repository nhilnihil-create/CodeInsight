
// Problem : B - Greedy Takahashi
// Contest : AtCoder - AtCoder Beginner Contest 149
// URL : https://atcoder.jp/contests/abc149/tasks/abc149_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
using namespace std;
int main()
{
	lli t,a,k,i,t1;
	cin>>t>>a>>k;
	t1=t;
	t=t-k;
	k=k-t1;
	if(k>0)
	a=a-k;
   if(t>0)
   cout<<t<<" ";
   else
   cout<<"0 ";
   if(a>0)
   cout<<a<<" ";
   else
   cout<<"0 ";
	return 0;
}