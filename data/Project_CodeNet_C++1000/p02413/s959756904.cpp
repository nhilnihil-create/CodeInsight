#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
int r,c;
cin >> r >> c;
int graph[r+1][c+1] ;

for(int i = 0; i<r+1; i++){
     for(int j = 0; j<c+1; j++){
          graph[i][j] = 0;
     }
}

for(int i = 0; i<r; i++){
     for(int j = 0; j<c; j++){
         cin >> graph[i][j];
     }
}
for(int i = 0; i<r; i++){
     for(int j = 0; j<c; j++){
          graph[i][c] += graph[i][j];
          graph[r][j] += graph[i][j];
          graph[r][c] += graph[i][j];
     }
}
for(int i = 0; i<r+1; i++){
     for(int j = 0; j<c+1; j++){
          if(j==c){
               cout << graph[i][j] ;
          }else{
               cout << graph[i][j] << " " ;
          }
     }cout << endl;
}
return 0;
}
