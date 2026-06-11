#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int h,w;
	cin>>h>>w;
	vector<string> maze(h);
	for(int i=0;i<h;i++) cin>>maze.at(i);

	vector<vector<int>> NumOfBlack(h,vector<int>(w,inf));
	if(maze.at(0).at(0)=='.') NumOfBlack.at(0).at(0)=0;
	else NumOfBlack.at(0).at(0)=1;

	queue<pair<int,int>> que;
	que.push(make_pair(0,0));

	while(!que.empty()){
		int x=que.front().first;
		int y=que.front().second;
		que.pop();

		vector<int> dx={0,1};
		vector<int> dy={1,0};

		for(int i=0;i<2;i++){
			int px=x+dx.at(i);
			int py=y+dy.at(i);
			if(px>=w || py>=h) continue;

			int add=0;
			if(maze.at(y).at(x)=='.' && maze.at(py).at(px)=='#') add=1;

			if(NumOfBlack.at(py).at(px)!=inf || px==0 || py==0) que.push(make_pair(px,py));

			NumOfBlack.at(py).at(px)=min(NumOfBlack.at(py).at(px),NumOfBlack.at(y).at(x)+add);
		}
	}

	cout<<NumOfBlack.at(h-1).at(w-1)<<endl;

	return 0;
}
