#include<iostream>
using namespace std;

int main(){
 int r,c;
 cin >> r >> c;
 int table[r+1][c+1]={};

 for(int i=0;i<r;++i){
  for(int j=0;j<c;++j){
   cin >> table[i][j];
  }
 }

 for(int i=0;i<r;++i){
  int sum=0;
  for(int j=0;j<c;++j){
   sum+=table[i][j];
   cout << table[i][j] << " ";
  }
  cout << sum << endl;
 }

 int sum2=0;
 for(int j=0;j<c;++j){
  int sum1=0;
  for(int i=0;i<r;++i){
   sum1+=table[i][j];
  }
  cout << sum1 << " ";
  sum2+=sum1;
 }
 cout << sum2 << endl;

 return 0;
}