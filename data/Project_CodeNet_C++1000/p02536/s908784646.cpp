#include <bits/stdc++.h>
using namespace std;

//par[i] contains the parent class of i 
vector<int> par;
 
int findpar(int n){
    //the root grandparent
	if(par[n]==n)
        return n;
	
    //updates all par[n] and all (parents of par[n]) to  same root grandparent
    return par[n]=findpar(par[n]);
}
 
void updaterelation(int a,int b){
    //find parent of a
	int p1=findpar(a);
    //find parent of b
	int p2=findpar(b);
    //make p1 as parent of p2 if already 
	par[p2]=p1;
}
 
int main(){

    int i,j,n,m,a,b;
    cin>>n>>m;

    par=vector<int>(n+1);

    //initially all members are root grandparent of themselves.
    for(i=1;i<=n;i++)
        par[i]=i;

    while(m--){ 
    	cin>>a>>b;
    	updaterelation(a,b);
    }
    
    set<int> s;
    for(i=1;i<=n;i++) {
        //find() is important to update all par[i] to their root grandparent values for uniformity.
        s.insert(findpar(i));
    }

    cout<<s.size()-1;
	return 0;
}