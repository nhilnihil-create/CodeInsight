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

//vi r(300003),c(300003);   

vii row(300004),col(300004);
map<lli,lli> points;
vii candx,candy;

lli has(lli x,lli y){
return x*1000000000000+y;
}

int main(){
    lli r,c,m;
    lli maxr,maxc;
    bool flag=true;
    maxr=maxc=0;
    cin>>r>>c>>m;
    foo(i,m){
    	lli x,y;
    	cin>>x>>y;
    	row[x]++;
    	col[y]++;
    	points[has(x,y)]++;
	}
	fo(i,r){
		maxr=max(maxr,row[i]);
	}
	fo(i,c){
		maxc=max(maxc,col[i]);
	}
	lli ans=maxr+maxc-1;
	
	fo(i,r){
		if(row[i]==maxr) candx.pb(i);
	}
	fo(i,c){
		if(col[i]==maxc) candy.pb(i);
	}
	
	foo(i,candx.size()){
		foo(j,candy.size()){
			if(points.find(has(candx[i],candy[j]))==points.end()){
				flag=false;
				ans++;
				break;
			}
		}
		if(!flag) break;
	}
	
	cout<<ans;
}


