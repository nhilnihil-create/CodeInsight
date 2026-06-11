#include<iostream>
using namespace std;
static const int N = 100;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int color[N];
int M[N][N];
int n,cnt;

void prim(){
	int d[N],p[N];
	for(int i=0;i<n;i++){
		color[i] = WHITE;
		d[i] = INFTY;
	}
	d[0]=0;p[0]=-1;
	int u;
	
	while(1){
		int mincost=INFTY;
		for(int i=0;i<n;i++){
			if(color[i] != BLACK && d[i] < mincost){
				mincost = d[i];
				u = i;
			}
		}
		if(mincost == INFTY)break;
		cnt += mincost;
		color[u] = BLACK;
		for(int i=0;i<n;i++){
			if(color[i] != BLACK && M[u][i] != INFTY){
				if(d[i] > M[u][i]){
					d[i] = M[u][i];
					p[i] = u;
					color[i] = GRAY;
				}
			}
		}
	}
}

int main(){
	cnt = 0;
	int d;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> d;
			M[i][j] = (d!=-1?d:INFTY);
		}
	}
	prim();
	cout << cnt << endl;
	return 0;
}

