#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define null (-1)
using namespace std;
struct node{int fa,se;};
int n;
int color[100000];
vector<int> a[100000];
void dft(int s,int d){

	stack<int> sd;
	sd.push(s);
  color[s]=d;
	while(!sd.empty()){
		int qw=sd.top();sd.pop();
		for(int i=0;i<a[qw].size();i++){
			int wq=a[qw][i];
			if(color[wq]==null){
			color[wq]=d;
				sd.push(wq);
			}
		}
	}
}
void colors(){
int i,j=1;
	for(i=0;i<n;i++){
	color[i]=null;
}
	for(i=0;i<n;i++){
	if(color[i]==null) 
	dft(i,j++);
    
    }
}
main(){
	int i,j,m,q,fo,fs;
 node g[100000];
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		cin>>fo>>fs;
		a[fo].push_back(fs);
		a[fs].push_back(fo);
	}
  cin>>q;
	for(i=0;i<q;i++){
		scanf("%d %d",&fo,&fs);	
     g[i].fa=fo;
      g[i].se=fs;
	}
	colors();
 for(i=0;i<q;i++){
	if(color[g[i].fa]==color[g[i].se])
		printf("yes\n");
		else
		printf("no\n");
 }
	return 0;
}

