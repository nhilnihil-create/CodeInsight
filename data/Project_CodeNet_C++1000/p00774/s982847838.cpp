#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1,1,-1,-1,1};
const int dy[]={-1,0,1,0,1,1,-1,-1};
const int INF = 1<<30;
const double EPS = 1e-15;
#define PB push_back
#define mk make_pair
#define fi first
#define se second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef pair<int,Pii> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector < Pii > deleteList;
int H,W;
int stage[12][6];

bool check(){
	deleteList.clear();
	bool flg = false;
	rep(i,H){
		reps(j,1,W-1){
			if(stage[i][j-1] != 0 && stage[i][j-1] == stage[i][j] && stage[i][j] == stage[i][j+1]){
				deleteList.PB(Pii(i,j-1));
				flg = true;
			}
		}
	}
	return flg;
}

int deleteBlock(){
	int ret = 0;
	rep(i,deleteList.size()){
		reps(j,deleteList[i].se,deleteList[i].se+3){
			if(stage[deleteList[i].fi][j] > 0)ret += stage[deleteList[i].fi][j];
			stage[deleteList[i].fi][j] = -1;
		}
	}
	return ret;
}

void dropBlock(){
	rep(i,H){
		rep(j,W){
			if(stage[i][j] == -1){
				while(stage[i][j] == -1){
					reps(k,i+1,H){
						stage[k-1][j] = stage[k][j];
					}
					stage[H-1][j] = 0;
				}
			}
		}
	}
	return ;
}

void DEBUGPRINT(){
	
	rep(i,H){
		rep(j,W){
			printf("%2d%c",stage[i][j],j==W-1?'\n':' ');
		}
	}
	puts("######################");
}

int main(){
	W = 5;
	while(scanf("%d",&H),H){
		memset(stage,-1,sizeof(stage));
		rep(i,H){
			rep(j,W){
				scanf("%d",&stage[H-i-1][j]);
			}
		}
		int score = 0;
		while(check()){
			//DEBUGPRINT();
			score += deleteBlock();
			dropBlock();
		}
		
		printf("%d\n",score);
	}
	return 0;
}