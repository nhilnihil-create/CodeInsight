#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<functional>
using namespace std;
#define LL long long
#define MOD 1000000007

int v,e,r,vc[1002],edge[2002][3];//s,t,d
bool NC = false, END;

int main(){
	cin >> v >> e >> r;
	for(int i=0; i<v; i++) vc[i] = MOD;
	for(int i=0; i<e; i++) cin >> edge[i][0] >> edge[i][1] >> edge[i][2];		
	
	vc[r] = 0;
	for(int i=0; i<v; i++){
		if(END)break;
		if(i == v-1){
			NC = true;
			break;
		}
		END = true;
		for(int j=0; j<e; j++){
			if((vc[edge[j][1]] > vc[edge[j][0]] + edge[j][2]) && vc[edge[j][0]] != MOD){
				END = false;
				vc[edge[j][1]] = vc[edge[j][0]] + edge[j][2];
			}
		}
	}

	if(NC && e)cout << "NEGATIVE CYCLE" << endl;
	else{
		for(int i=0; i<v; i++){
			if(vc[i] == MOD) cout << "INF" <<endl;
			else cout << vc[i] << endl;
		}
	}
	return 0;
}


