#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long int lli;
const long long int MaxN=3005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	
	priority_queue <lli> pq;
	void solve(){
		lli N,M,i,j,p,q,res=0;
		cin>>N>>M;
		for(i=0;i<N;i++){
			cin>>p;
			pq.push(p);
		}
		while(M--){
			p=pq.top();
			p=p/2;
			pq.pop();
			pq.push(p);
		}
		while(!pq.empty()){
			p=pq.top();
			res+=p;
			pq.pop();
		}
		cout<<res<<"\n";
	}	
int main(){
	//cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,j,t; 
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
	
}