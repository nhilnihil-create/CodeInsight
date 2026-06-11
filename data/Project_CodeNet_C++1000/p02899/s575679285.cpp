#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> a(N+1,0);
  for(int i=1;i<N+1;i++){
    cin>>a.at(i);
  }//代入
  vector<int> b(N+1,0);
  /*for(int i=1;i<N+1;i++){
    for(int j=1;j<N+1;j++){
      if(a.at(j)==i){
        b.at(i)=j;
      }
    }
  }*///ここがO(n^2)でTLE
  for(int i=1;i<N+1;i++){
    b.at(a.at(i))=i;
  }//いつ出席番号何番の生徒が来たか記録
  for(int i=1;i<N+1;i++){
    cout<<b.at(i);
    if(i!=N){
    cout<<" ";
     }
  }
  cout<<endl;
}
