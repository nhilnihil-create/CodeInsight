// Created by code_sm
//
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp> 
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> pseudo_set;
#define ll long long
#define vi vector<int>
#define si set<int> 
#define mii map<int,int>
#define pb push_back
#define pf push_front
#define pii pair<int,int>
#define extract_word(s)  stringstream str(s); while(str>>word)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SET(s) cout<<fixed<<setprecision(s)
#define chotu 1000000007
#define set0(a) memset(a,0,sizeof(a))
#define endl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lower_string(s) transform(all(s),s.begin(),::tolower())
#define upper_string(s) transform(all(s),s.begin(),::toupper())
#define size(s) s.size()
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<typename T,typename U>
bool compare(T x,U y){return(abs(x-y)<=1e-9);}
void solve()
{
fastio
	int n;
	cin>>n;
	vi w(n);
	for(int i=0;i<n;i++)
		cin>>w[i];
	int min_val=10000000;
	for(int i=0;i<n-1;i++)
	{
		int sum1=0,sum2=0;
		for(int j=0;j<=i;j++)
			sum1+=w[j];
		for(int k=i+1;k<n;k++)
			sum2+=w[k];
		min_val=min(min_val,abs(sum1-sum2));
	}
	cout<<min_val;
}
int main()
{
//code
	
fastio	
int t;
t=1;
while(t--)
{
	solve();
	cout<<endl;
}
}
