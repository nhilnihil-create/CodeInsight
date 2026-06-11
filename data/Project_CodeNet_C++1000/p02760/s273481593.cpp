#include <bits/stdc++.h>
using namespace std;
int main(){
int bingo[3][3];
  for(int i=0;i<3;i++){
  	for(int j=0;j<3;j++){
    	cin>>bingo[i][j];
    }
  }
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
  	int a;
    cin>>a;
    for(int i=0;i<3;i++){
  		for(int j=0;j<3;j++){
    		if(bingo[i][j]==a){
            bingo[i][j]=12345;
            }
   		}
  	}
  }
  bool nazo=false;
 for(int i=0;i<3;i++){
 	if(bingo[i][0]==bingo[i][1] && bingo[i][1]==bingo[i][2]){
    nazo=true;
    }
   	if(bingo[0][i]==bingo[1][i] && bingo[1][i] ==bingo[2][i]){
    nazo=true;
    }
 }
  if(bingo[0][0]==bingo[1][1] && bingo[1][1]==bingo[2][2]){
  nazo=true;
  }
  if(bingo[0][2]==bingo[1][1] && bingo[1][1]==bingo[2][0]){
  nazo=true;
  }
  if(nazo){
  cout<<"Yes";
  }
  else{
  cout<<"No"<<endl;  
  }
}