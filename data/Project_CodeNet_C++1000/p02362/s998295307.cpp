#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reg(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second


bool belfo(int n,int s,vector<mp>* vs,int* dist,int* gone){
	memset(gone,-1,sizeof(int)*n);
	gone[s]=1;
	dist[s]=0;
	
	rep(k,n+1){
		if(k==n)return false;
		bool ch=false;
		rep(no,n){
			if(gone[no]==-1)continue;
			int nc=dist[no];
			rep(i,vs[no].size()){
				int to=vs[no][i].fir,
					co=vs[no][i].sec;
				if(gone[to]==-1 || dist[to]>nc+co){
					dist[to]=nc+co;
					gone[to]=1;
					ch=true;
				}
			}
		}
		if(!ch)break;
	}
	return true;
}



	
	
	
int n,m;

vector<mp> vs[100005];


int dist[100005];
int gone[100005];




int main(void){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	rep(i,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		vs[a].push_back(mp(b,c));
		//vs[b].push_back(mp(a,c));
	}
	if(belfo(n,s,vs,dist,gone)){
		rep(i,n){
			if(gone[i]!=-1)printf("%d\n",dist[i]);
			else printf("INF\n");
		}
	}
	else printf("NEGATIVE CYCLE\n");
	return 0;
	
}