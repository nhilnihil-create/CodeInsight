#include <bits/stdc++.h>
using namespace std;


int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>> p(H,vector<char>(W));
  vector<vector<int>> q(H,vector<int>(W,100000));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>p.at(i).at(j);
    }
  }
  if(p.at(0).at(0)=='#'){
    q.at(0).at(0)=1;
  }
  else{
    q.at(0).at(0)=0;
  }
  for(int i=0;i<H+W-2;i++){
    int a=max(i-W+1,0),b=min(W-1,i);
    while(a<H&&b>=0){
      if(a!=H-1){
        if(p.at(a).at(b)=='.'&&p.at(a+1).at(b)=='#'){
          q.at(a+1).at(b)=min(q.at(a+1).at(b),q.at(a).at(b)+1);
        }
        else{
          q.at(a+1).at(b)=min(q.at(a+1).at(b),q.at(a).at(b));
        }
      }
      if(b!=W-1){
        if(p.at(a).at(b)=='.'&&p.at(a).at(b+1)=='#'){
          q.at(a).at(b+1)=min(q.at(a).at(b+1),q.at(a).at(b)+1);
        }
        else{
          q.at(a).at(b+1)=min(q.at(a).at(b+1),q.at(a).at(b));
        }
      }
      a++,b--;
    }
  }
  cout<<q.at(H-1).at(W-1)<<endl;
}