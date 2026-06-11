#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int S;
  int W;
  cin>>S;
  cin>>W;
  if(W >= S){
    cout<<"unsafe"<<'\n';
  }else{
    cout<<"safe"<<'\n';
  }
}