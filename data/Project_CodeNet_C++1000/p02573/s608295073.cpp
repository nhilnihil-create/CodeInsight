#include <iostream>
using namespace std;

int parent[(int)2e5+6];
int rnk[(int)2e5+6];
int numOfnodes[(int)2e5+6];
//int maxi=0;

void DSU(){
	for(int i=0;i<(int)2e5+6;i++){
		parent[i]=i;
	}
	for(int i=0;i<(int)2e5+6;i++){
		rnk[i]=0;
		numOfnodes[i]=1;
	}
}

int findparent(int node){
	if(parent[node]==node)return node;
	//c2++;
	//if(maxi<c2)maxi=c2;
	return parent[node]=findparent(parent[node]);
}

bool isConnected(int a,int b){
	if(findparent(a)==findparent(b))return true;
	return false;
}

void connect(int a,int b){
	int tmpa=findparent(a);
	int tmpb=findparent(b);
	if(rnk[tmpa]>rnk[tmpb]){parent[tmpb]=tmpa; numOfnodes[tmpa]+= numOfnodes[tmpb];}
	else if(rnk[tmpa]<rnk[tmpb]){parent[tmpa]=tmpb; numOfnodes[tmpb]+=numOfnodes[tmpa];}
	else {parent[tmpb]=tmpa; rnk[tmpa]++; numOfnodes[tmpa]+= numOfnodes[tmpb];}
}

int main() {
	DSU();
	int nodes,edges,a,b,ans=0;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		cin>>a>>b;
		if(!isConnected(a,b)){
			connect(a,b);
		}
	}
	for(int i=1;i<=nodes;i++){
		if(findparent(i)==i&&ans<numOfnodes[i])ans=numOfnodes[i];
	}

	cout<<ans<<endl;
	return 0;
}
