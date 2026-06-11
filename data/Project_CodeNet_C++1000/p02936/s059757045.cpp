#include <iostream>
#include <vector>
using namespace std;

void dfs(long long a[],vector<int>v[],int r,bool visited[]){
    visited[r]=true;
    for(vector<int>::iterator it=v[r].begin();it!=v[r].end();it++){
        if(!visited[*it]){
            a[*it]+=a[r];
            dfs(a,v,*it,visited);
        }
    }
}

int main() {
	int n,q,A,B,p,x;
	cin>>n>>q;
	long long a[n];
	vector<int>v[n];
	bool visited[n];
	for(int i=0;i<n;i++){
	    a[i]=0;
	    visited[i]=false;
	}
	for(int i=1;i<=n-1;i++){
	    cin>>A>>B;
	    A--;
	    B--;
	    v[A].push_back(B);
	    v[B].push_back(A);
	}
	for(int i=1;i<=q;i++){
	    cin>>p>>x;
	    a[p-1]+=x;
	}
	dfs(a,v,0,visited);
	for(int i=0;i<n;i++){
	    cout<<a[i]<<' ';
	}
	return 0;
}