#include<bits/stdc++.h>
using namespace std;
#define Int long long
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b)a=b;}

struct FastIO{
	FastIO(){
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
	Int n;
	cin>>n;
	vector<Int> as(n);
	for(Int i=0;i<n;i++)cin>>as[i],as[i]--;
	
	vector<Int> cs(n,0);
	//for(int a=0;a<as.size();++a)と同様
	for(Int a:as) 
	{
		cs[a]++;
	}
	
	vector<Int> ds(n+1,0);
	for(Int c:cs)
	{
		ds[c]++;
	}
	
	vector<Int> sm1(n+2,0),sm2(n+2,0);
	for(Int i=0;i<=n;i++){
		sm1[i+1]=sm1[i]+i*ds[i];
		sm2[i+1]=sm2[i]+1*ds[i];
	}
	vector<Int> fs(n+1,n+1);
	for(Int i=1;i<=n;i++)
	{
		fs[i]=(sm1[i+1]+i*(sm2[n+1]-sm2[i+1]))/i;
	}
	for(Int k=1,p=n;k<=n;k++){
		while(k>fs[p])p--;
		cout<<p<<"\n";
	}
	cout<<flush;
	return 0;
}
