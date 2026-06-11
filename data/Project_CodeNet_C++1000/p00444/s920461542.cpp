#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 3000
using namespace std;

int C[6]={1,5,10,50,100,500};
int T[MAX+1];
void douteki();

int main(){
  int n;
 

  while(1){
    cin >> n;
    if(n == 0)break; 
    douteki();
    cout << T[1000-n] << endl;
  }



}

void douteki(){
  for(int j=0;j<=MAX;j++)T[j]=10000;
  T[0]=0;
  for(int i=0;i<6;i++){
    for(int j=C[i];j<=MAX;j++){
      T[j]=min(T[j],T[j-C[i]]+1);
    }
  }

}