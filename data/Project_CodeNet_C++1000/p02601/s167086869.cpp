#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define lli long long int
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define vii vector<lli>

#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<lli,lli>>
#include <map>           
lli mod=1000000007;      

vi r(300003),c(300003);   

int main(){
   int a,b,c,k;
   cin>>a>>b>>c>>k;
   if(a>=b){
   while(a>=b){
   	b*=2;
   	k--;
   }
   }
   if(c<=b){
   	while(c<=b){
   		c*=2;
   		k--;
	   }
   }
  if(k>=0) cout<<"Yes";
  else cout<<"No";
}

/*int main(){
	lli n,k;
	lli prod=1,temp;
	cin>>n>>k;
	vii v(n);
	vii t;
	vi ans;
	foo(i,n) cin>>v[i];
	foo(i,k) prod*=v[i];
	temp=prod;
	int d=0;
	for(int i=k;i<n;i++){
		prod/=v[d];
		prod*=v[i];
		t.pb(prod);
		d++;
	}
	if(temp<t[0]) ans.pb(1);
	else ans.pb(0);
	for(int i=1;i<t.size();i++){
		if(t[i]>t[i-1])
		ans.pb(1);
		else ans.pb(0);
	}
	
	foo(i,t.size()) cout<<t[i]<<" ";
	foo(i,ans.size()){
		if(ans[i]) cout<<"Yes\n";
		else cout<<"No\n";
	}
}*/
