#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,k,q;
  cin>>n>>k>>q;
  vector<int> score(n,k-q);
  for(int i=0;i<q;i++){
    int r;
    cin>>r;
    ++score[r-1];
  }
  for(int i=0;i<n;i++){
    if(score[i]>0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}