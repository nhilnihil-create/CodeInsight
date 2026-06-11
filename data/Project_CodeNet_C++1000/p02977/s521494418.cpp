#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int N,Root=1;
vector<int>P[MAXN];
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%d",&N);
	if(int(log2(N))==log2(N)){
		printf("No\n");
		return 0;
	}
	P[1].push_back(2);
	P[2].push_back(3);
	P[3].push_back(1+N);
	P[1+N].push_back(2+N);
	P[2+N].push_back(3+N);
	for(int i=4;i<N;i+=2){
		P[Root].push_back(i);
		P[Root].push_back(i+N+1);
		P[i].push_back(i+1);
		P[i+N+1].push_back(i+N);
	}
	if(N%2==0){
		int ed=N,f=0,Sum=0;
		for(int i=25;i>=0;i--)
			if(ed&(1<<i))f=(1<<i),Sum+=f;
		int t1,t2;
		t1=f,t2=Sum-t1+N+1;
		P[ed].push_back(t1);
		P[ed+N].push_back(t2);
	}
	printf("Yes\n");
	for(int i=1;i<=2*N;i++){
		int size=P[i].size();
		for(int j=0;j<size;j++)
			printf("%d %d\n",i,P[i][j]);
	}
}