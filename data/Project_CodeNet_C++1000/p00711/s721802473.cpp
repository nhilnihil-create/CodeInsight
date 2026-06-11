#include <iostream>

#include <string>
#include <queue>

using namespace std;

int main(){
	int w,h;
	int data[30][30];
	int flag[30][30];
	int dx[4] ={0,1,0,-1};
	int dy[4] ={1,0,-1,0};

	while(1){
		cin>>w>>h;
		if(w==0 && h==0)break;

	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			data[i][j]=-1;
			flag[i][j]=0;
		}
	}

	char tmp;
	int startX;
	int startY;
	int cnt=0;

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>tmp;
			if(tmp=='.')data[i][j] = 0;
			else if(tmp=='@'){
				startX = j;
				startY = i;
			}
		}
	}

	queue<int> qX,qY;
	qX.push(startX);
	qY.push(startY);

	while(qX.size()!=0){
		int topX = qX.front();
		int topY = qY.front();
		qX.pop();
		qY.pop();
		cnt++;

		for(int i=0;i<4;i++){
			int nowX = topX + dx[i];
			int nowY = topY + dy[i];

			if(data[nowY][nowX] ==0 && flag[nowY][nowX] == 0){
				qX.push(nowX);
				qY.push(nowY);
				flag[nowY][nowX]=1;
			}
		}
	}

	cout<<cnt<<endl;
	}

	return 0;
}