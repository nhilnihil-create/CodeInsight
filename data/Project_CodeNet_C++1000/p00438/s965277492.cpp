#include<iostream>
#include<queue>

using namespace std;

typedef struct{
  int x;
  int y;
}Point;

int main(){

  Point goal;
  while(cin >> goal.x >> goal.y && goal.x + goal.y){
    int sum = 0;
    int data[goal.y+1][goal.x+1];
    for(int i = 0; i <= goal.y; i++){
      for(int j = 0; j <= goal.x; j++){
      	data[i][j] = 1;
     }
    }
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
      int a,b;
      cin >> a >> b;
      data[b][a] = 0;
    }

    queue<Point> Q;
    Point init;
    init.x = init.y = 1;
    Q.push(init);
    while(!Q.empty()){
      Point now = Q.front();
      Q.pop();
      if(now.x == goal.x && now.y == goal.y){
	sum++;
	continue;
      }
      if(now.x < goal.x){
	if(data[now.y][now.x+1]){
	  Point next;
	  next.x = now.x+1;
	  next.y = now.y;
	  Q.push(next);
	}
      }
      if(now.y < goal.y){
	if(data[now.y+1][now.x]){
	  Point next;
	  next.x = now.x;
	  next.y = now.y+1;
	  Q.push(next);
	}
      }
    }
    cout << sum << endl;
  }
  return 0;
}