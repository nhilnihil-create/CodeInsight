#include <iostream>
using namespace std;

int main(){
  int n,i,j,rank,s=0;
  bool card[4][13];
  for (i=0;i<4;i++){
    for (j=0;j<13;j++)card[i][j]=true;
  }
  string suit;
  cin>>n;
  for (i=0;i<n;i++){
    cin>>suit>>rank;
    if (suit=="S")card[0][rank-1]=false;
    else if (suit=="H")card[1][rank-1]=false;
    else if (suit=="C")card[2][rank-1]=false;
    else if (suit=="D")card[3][rank-1]=false;
  }
  for (i=0;i<4;i++){
    for (j=0;j<13;j++){
      if(card[i][j]){
        if (i==0)cout<<"S "<<j+1<<endl;
        else if (i==1)cout<<"H "<<j+1<<endl;
        else if (i==2)cout<<"C "<<j+1<<endl;
        else if (i==3)cout<<"D "<<j+1<<endl;
      }
    }
  }
  return 0;
}

