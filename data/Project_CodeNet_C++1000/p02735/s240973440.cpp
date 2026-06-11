#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++)
    cin>>s.at(i);
  vector<vector<vector<int>>> b(h+1,vector<vector<int>>(w+1,vector<int>(2,h*w)));
  b[0][1][0]=0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(s.at(i-1).at(j-1)=='#')
        b[i][j][1]=min({b[i-1][j][0]+1,b[i][j-1][0]+1,b[i-1][j][1],b[i][j-1][1]});
      else
        b[i][j][0]=min({b[i-1][j][0],b[i][j-1][0],b[i-1][j][1],b[i][j-1][1]});
    }
  }
  cout<<min(b[h][w][0],b[h][w][1])<<endl;
}