#include <iostream>
using namespace std;

int field[20][20];
int w,h;
int bfs(int, int);

int main(){
  int x,y;

  while(cin>>w>>h&&w!=0&&h!=0){
    for(int j=0;j<h;j++){
      for(int i=0;i<w;i++){
        char c;
        cin >> c;
        if(c=='.')field[i][j]=1;
        else if(c=='#')field[i][j]=-1;
        else if(c=='@'){
          field[i][j]=0; 
          x=i;
          y=j;
        }
      }
    }
    int ans=bfs(x, y);
    cout << ans+1 << endl;
  }

  return 0;
}

int bfs(int x, int y){
  int count=0;
  if(y-1>=0&&field[x][y-1]==1){
    field[x][y-1]=-1;
    count++;
    count+=bfs(x, y-1);
  }
  if(y+1<h&&field[x][y+1]==1){
    field[x][y+1]=-1;
    count++;
    count+=bfs(x, y+1);
  }
  if(x-1>=0&&field[x-1][y]==1){
    field[x-1][y]=-1;
    count++;
    count+=bfs(x-1, y);
  }
  if(x+1<w&&field[x+1][y]==1){
    field[x+1][y]=-1;
    count++;
    count+=bfs(x+1, y);
  }
  return count;
}