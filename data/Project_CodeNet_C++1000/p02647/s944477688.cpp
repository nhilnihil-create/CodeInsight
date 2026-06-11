#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
/****************************/
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
#define qi queue<int>
#define mii map<int,int>
#define msi map<string,int>
#define vs vector<string>
#define vc vector<char>
/****************************/
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=(n)-1;i>=0;i--)
#define rep3(i,a,n) for(int i=(a);i<(n);i++)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define pi 3.1415926535897932384626433832795
#define zero(n) memset(n,0,sizeof(n));
#define SZ(n) n.size()
#define ss st.st
#define sn st.nd 
/****************************/
using namespace std;
int n,k;
int a[200010],b[200010];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	rep(i,n) cin>>a[i];
	rep(i,k)
	{
		zero(b);
		rep(j,n)
		{
			int left=max(0,j-a[j]);
			int right=min(n,j+a[j]+1);
			b[left]++;
			b[right]--;
		}
		bool all=true;
		a[0]=b[0];
		if(a[0]!=n) all=false;
		rep3(j,1,n)
		{
			b[j]+=b[j-1];
			a[j]=b[j];
			if(a[j]!=n) all=false;
		}
		if(all) break;
	}
	rep(i,n) cout<<a[i]<<endl;
	return 0;                                                                                                                                     
}