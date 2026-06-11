#include<bits/stdc++.h>
#include<iostream>
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
#include<queue>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
/************************************************/
#define rep(i,n) for(int i=0;i<n;i++)
#define m_p make_pair
#define pb push_back
#define fr first
#define se second
#define forn(i,a,n) for(int i=a;i<n;i++)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();i++)
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define sz(s) s.size()
#define all(s) s.begin(),s.end()
#define zero(x) memset(x,0,sizeof(x))
#define vii vector<pair<int,int> >
#define mpis map<int,string>
#define mpii map<int,int>
#define mpsi map<string,int>
#define re return
#define mod 1000000007
/************************************************/
using namespace std;

long long get(){
	char c=getchar();
	long long x=0LL;
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9'){
		x*=10LL;
		x+=(c-'0');
		c=getchar();
	}
	return x;
}
int n,a[1001][1000];
int d[1001][1001];
int z[1001];
bool f[1001];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	rep(i,n)
	rep(j,n-1){
		cin>>a[i][j];
		a[i][j]--;
		d[i][a[i][j]]=j;
	}
	int nw=0,ans=0;
	while(nw<n*(n-1)){
		int nnw=0;
		zero(f);
		rep(i,n){
			if(f[i]||f[a[i][z[i]]])
			continue;
			if(d[a[i][z[i]]][i]-z[a[i][z[i]]]==0){
				nnw+=2;
				f[i]=true;
				f[a[i][z[i]]]=true;
				z[a[i][z[i]]]++;
				z[i]++;
			}
		}
		if(nnw==0){
			cout<<-1;
			re 0;
		}
		nw+=nnw;
		ans++;
	}
	cout<<ans;
	re 0;
}
