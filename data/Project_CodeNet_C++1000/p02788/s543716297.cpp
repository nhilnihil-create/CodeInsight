#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d,a;
  cin>>n>>d>>a;
  vector<vector<int>> xh(n,vector<int>(2));
  for(int i=0;i<n;i++)
    cin>>xh.at(i).at(0)>>xh.at(i).at(1);
  sort(xh.begin(),xh.end());
  int64_t c=0;
  int64_t sa=0;
  queue<vector<int64_t>> q;
  for(int i=0;i<n;i++){
    int64_t x=xh.at(i).at(0);
    int64_t h=xh.at(i).at(1);
    while(!q.empty()){
      int64_t qx=q.front().at(0);
      int64_t qa=q.front().at(1);
      if(x>qx){
        sa-=qa;
        q.pop();
      }else
        break;
    }
    h=max(h-sa,(int64_t)0);
    c+=(h+a-1)/a;
    sa+=(h+a-1)/a*a;
    q.push({x+d*2,(h+a-1)/a*a});
  }
  cout<<c<<endl;
}