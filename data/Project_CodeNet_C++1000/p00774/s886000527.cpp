#include<iostream>
#include<queue>
using namespace std;

queue <int>que;
int mas[12][6];
int h;
int cheak;
int a,t;
int p;
int size;

int bfs(int y){
  int ans=0;
  if(mas[y][1]==mas[y][2] && mas[y][1]==mas[y][3]){
    ans=mas[y][2]*3;
    if(mas[y][0]==mas[y][1] && mas[y][1]==mas[y][4]){
      ans=mas[y][2]*5;
      mas[y][0]=0;
      mas[y][4]=0;
    }
    else if(mas[y][0]==mas[y][1]){
      ans=mas[y][2]*4;
      mas[y][0]=0;
    }
    else if(mas[y][4]==mas[y][1]){
      ans=mas[y][2]*4;
      mas[y][4]=0;
    }
    mas[y][1]=0;
    mas[y][2]=0;
    mas[y][3]=0;
  }

  else if(mas[y][0]==mas[y][1] && mas[y][0]==mas[y][2]){
    ans=mas[y][2]*3;
    mas[y][0]=0;
    mas[y][1]=0;
    mas[y][2]=0;
  }
  else if(mas[y][2]==mas[y][3] && mas[y][2]==mas[y][4]){
    ans=mas[y][2]*3;
    mas[y][2]=0;
    mas[y][3]=0;
    mas[y][4]=0;
  }

  return ans;
}


main(){
  while(cin >> h,h){
    a=0;
    for(int i=0;i<h;i++){
      for(int j=0;j<5;j++){
	cin >> mas[i][j];
      }
    }
    
    while(1){
      cheak=0;
      t=0;
      for(int i=0;i<h;i++){
	t=bfs(i);
	if(t!=0)cheak=1;
	a+=t;
      }

      if(cheak==0)break;

      for(int i=0;i<5;i++){
	int d=0;
	for(int j=0;j<h;j++){
	  if(mas[j][i]>0)que.push(mas[j][i]);
	}
	size=que.size();

	for(int j=0;j<h-size;j++){
	  mas[j][i]=0;
	} 
	for(int j=h-size;j<h;j++){
	  mas[j][i]=que.front();
	  que.pop();
	}
      }

    }
    cout << a << endl;
  }
}