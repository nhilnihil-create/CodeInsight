#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef struct{
  int begin;
  int end;
  bool f;
}fint;
fint T[101];
 
int times = 1;
int n;
int graph[101][101];
 
void bfs(int now){
 
  T[now].f = true;
  T[now].begin = times++;
 
  for( int i = 1 ; i <= n; i++ ){
    if( graph[now][i] == 1 && !T[i].f ) bfs(i);
  }
  T[now].end = times++;
 
}
 
int main(void){
 
  int s,t,u;
  cin >> n;
  for( int i = 0 ; i < n ; i++ ){
    cin >> s >> t;
    for( int j = 1 ; j <= t ; j++ ){
      cin >> u;
      graph[s][u] = 1;
    }
  }
  for( int i = 1 ; i <= n ; i++ ){
    T[i].begin = 0;
    T[i].end = 0;
    T[i].f = false;
  }
  for( int i = 1 ; i <= n ; i++ ){
    if( !T[i].f ) bfs(i);
  }
 
  for( int i = 1 ; i <= n ; i++ ){
    cout << i << " " << T[i].begin << " " << T[i].end << endl;
  }
 
 
  return 0;
}
