#include<iostream>
#include<cstring>
#include<set> 
#include<queue>
#include<list> 
#include<vector>
const int maxn=500000+5;
using namespace std;

vector<int> v[maxn];
long long zero=0,one=0;
struct pp{
	int data;
	int zt;
};
int vis[maxn]; 
queue<int> p;
int bj[maxn];
void bfs(){
	while(!p.empty()){
	      int x=p.front();
//		  if(x.zt==0)
//		  zero++;
//		  else
//		  one++;
		  p.pop();
		  for(int i=0;i<v[x].size();i++){
		  	    if(vis[v[x][i]]==0){
		vis[v[x][i]]=1;
				  bj[v[x][i]]=x;
		  	    p.push(v[x][i]);}
		  }
		}
	} 
int main()
{  
	
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		
		}
		 p.push(1);
		 vis[1]=1;
		 bfs();
		 int k=0;
		 for(int i=2;i<=n;i++){
		 	if(bj[i]==0)
		 	{ k==1;
		 	  break;
			 }
		 } 
		 if(k==1)
		 cout<<"No"<<endl;
		 else
		 {
		  cout<<"Yes"<<endl; 
		 for(int i=2;i<=n;i++){
		 	cout<<bj[i]<<endl;
		 }
}

	
	
	
}
