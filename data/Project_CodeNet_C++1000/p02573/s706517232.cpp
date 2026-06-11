#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;

vector<int> par;


int find(int n){
	if(par[n]<0)return n;
	return par[n]=find(par[n]);
}

void uni(int a,int b){
	par[a]+=par[b];
	par[b]=a;
}
 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i,j,k,n,m;
    cin>>n>>m;
    par=vector<int>(n+1,-1);
    int x,y;
    while(m--){
    	cin>>x>>y;
    	x=find(x);
    	y=find(y);
    	if(x!=y)uni(x,y);
    }
    cout<<-*min_element(par.begin(), par.end());


 
	
	
	
 
 
 
 
 
 
 
	return 0;
}