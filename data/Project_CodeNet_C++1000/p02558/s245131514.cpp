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
string i_t_s(int x){
	string t="";
	while(x){
		t+=x%10+'0';
		x/=10;
	}
	reverse(all(t));
	re t;
}
int s_t_i(string t){
	int x=0;
	rep(i,sz(t)){
		x=x*10+(t[i]-'0');
	}
	re x;
}
int n,q;
int a[200001];
int dfs(int x){
	if(a[x]==x)
	re x;
	a[x]=dfs(a[x]);
	re a[x];
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	rep(i,n)
	a[i]=i;
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(t){
			dfs(x);
			dfs(y);
			if(a[x]!=a[y])
			cout<<"0\n";
			else
			cout<<"1\n";
		}else{
			a[dfs(y)]=dfs(x);
		}
	}
	re 0;
}
