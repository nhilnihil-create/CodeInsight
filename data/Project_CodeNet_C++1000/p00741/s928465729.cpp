#include <iostream>
#include <vector>
using namespace std;
int d[3] = {0,1,-1};
void dfs(int x,int y,vector<vector<int> > &field){
  if((x < 0 || y < 0 || x >= field[0].size() || y >= field.size()) || field[y][x] == 0)return ;
  field[y][x] = 0;
  for(int i = -1;i <= 1;i++){
	for(int j = -1;j <= 1;j++){
	  if(i == 0 && j == 0)continue;
	  dfs(x+i,y+j,field);
	}
  }
  
}

int main(){
  int w,h;
  while(cin >> w >> h && w && h){
	vector<vector<int> > field(h,vector<int>(w,0));
	for(int i = 0;i < h;i++){
	  for(int j = 0;j < w;j++){
		cin >> field[i][j];
	  }
	}
	int ans = 0;
	for(int i = 0;i < h;i++){
	  for(int j =0;j < w;j++){
		if(field[i][j] == 1){
		  dfs(j,i,field);
		  ans++;
		}
	  }
	}
	cout << ans << endl;
  }
  return 0;
}