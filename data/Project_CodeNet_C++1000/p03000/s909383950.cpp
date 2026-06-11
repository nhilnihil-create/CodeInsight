#include <bits/stdc++.h>
using namespace std;
int main(){
int N,X;
  cin>>N>>X;
  int counter=1;
  int zahyo=0;
  vector<int>moji(N);
  for(int i=0;i<N;i++){
  cin>>moji.at(i);
  }
  for(int i=0;i<N;i++){
   if(zahyo+moji.at(i) <=X){
   counter++;
     zahyo+=moji.at(i);
   }
    else{
    break;
    }
  }
  cout<<counter<<endl;
}