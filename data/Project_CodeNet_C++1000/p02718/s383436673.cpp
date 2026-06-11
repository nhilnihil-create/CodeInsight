#include <bits/stdc++.h>
using namespace std;
int main(){
int N,M;
  cin>>N>>M;
  vector<int>moji(N);
  for(int i=0;i<N;i++){
  cin>>moji.at(i);
  }
  int sum=0;
   for(int i=0;i<N;i++){
 	sum+=moji.at(i);
  }
  int count;
 for(int i=0;i<N;i++){
   if(moji.at(i)*(4*M)>=sum){
   count++;
   }
  }
  if(count>=M){
  cout<<"Yes";
  }
  else{
  cout<<"No";
  }
}