#include<bits/stdc++.h>
using namespace std;
int solve(int* L, int* R,int* d){
  int count=0;
  for(int i=*L;i<=*R;i++){
  if(i%*d==0){
    count++;
  }
  }
  return count;
}
int main(){
  int L=0,R=0,d=0;
  cin>>L>>R>>d;
  cout<<solve(&L,&R,&d)<<'\n';
}