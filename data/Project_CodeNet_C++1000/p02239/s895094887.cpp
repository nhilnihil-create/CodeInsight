#include<iostream>
#include<queue>
using namespace std;
int M[101][101];
int n;
int d[101];

int search(int s){
    queue<int> Q;
    int u;

    Q.push(s);
    d[s]=0;

    while( !Q.empty() ){
	u=Q.front(); Q.pop();

	for(int i=1;i<=n;i++){
	    if(M[u][i]==0) continue;
	    if(d[i]>0) continue;
    
	    d[i]=d[u]+1;
	    Q.push(i);
	}

    }
}
    
int main(){
    int u,k,v;

    cin >> n;
    for(int i=0;i<n;i++){
	cin >> u >> k;
	for(int j=0;j<k;j++){
	    cin >> v;
	    M[u][v]=1;
	}
    }

    search(1);

    cout << 1 << " " << 0 << endl;
    for(int i=2;i<=n;i++){
	if(d[i]==0) cout << i << " " << -1 << endl;
	else cout << i << " " << d[i] << endl;
    }

    return 0;
}