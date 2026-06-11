#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
vector<int> par;
 
int find(int n){
	if(par[n]==n)
        return n;
	else 
        return par[n]=find(par[n]);
}
 
void uni(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b)
        par[b]=a;
}
 
int main(){

    int i,j,n,m,a,b;
    cin>>n>>m;

    par=vector<int>(n+1);

    for(i=1;i<=n;i++)
        par[i]=i;

    while(m--){
    	cin>>a>>b;
    	uni(a,b);
    }
    
    set<int> s;
    for(i=1;i<=n;i++)
        s.insert(find(i));

    cout<<s.size()-1;
	return 0;
}