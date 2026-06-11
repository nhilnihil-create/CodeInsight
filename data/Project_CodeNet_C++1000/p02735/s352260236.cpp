//agc043_a.cpp
//Thu May 28 21:14:16 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int h,w;
	cin >> h >> w;

	int col[h][w];
	int visited[h][w];
	for (int i=0;i<h;i++){
		string s;
		cin >> s;
		for (int j=0;j<w;j++){
			if (s[j]=='.'){
				col[i][j]=0;
			}else {
				col[i][j]=1;
			}
			visited[i][j] = 0;
		}
	}

	queue<P> q;
	int flip = 0;
	q.push(P(0,0));
	int qcol[2];
	if (col[0][0]==0){
		qcol[0] = 1;
		qcol[1] = 0;
	}else {
		qcol[0] = 0;
		qcol[1] = 1;
	}

	while(!q.empty()){
		if (qcol[flip%2]==0){
			flip++;
		}
		P x = q.front();q.pop();
		if (visited[x.first][x.second]){
			qcol[col[x.first][x.second]]--;
		}else if (col[x.first][x.second]==flip%2){
			visited[x.first][x.second] = 1;
			qcol[col[x.first][x.second]]--;
			if (x.first==h-1 && x.second==w-1){
				break;
			}
			if (x.second!=w-1){
				q.push(P(x.first,x.second+1));
				qcol[col[x.first][x.second+1]]++;
			}
			if (x.first!=h-1){
				q.push(P(x.first+1,x.second));
				qcol[col[x.first+1][x.second]]++;
			}
		}else {
			q.push(x);
		}
		// cout << flip << " " << qcol[0] << " " << qcol[1] <<endl;
	}

	cout << (flip+1)/2 << endl;
//	printf("%.4f\n",ans);
}