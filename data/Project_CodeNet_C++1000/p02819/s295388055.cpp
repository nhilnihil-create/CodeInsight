
// Problem : C - Next Prime
// Contest : AtCoder - AtCoder Beginner Contest 149
// URL : https://atcoder.jp/contests/abc149/tasks/abc149_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
using namespace std;
#define MAX 1000007
int main()
{
	lli t,a,i;
	vector<bool>is_p(MAX,true);
	is_p[0]=false;
	is_p[1]=false;
	for(i=2;i<MAX;i++)
	{
		if(is_p[i]==true){
			for(lli j=i*i;j<MAX;j+=i){
				is_p[j]=false;
			}
		}
	}
	cin>>t;
	while(!is_p[t]){
		t++;
	}
	cout<<t;
	return 0;
}