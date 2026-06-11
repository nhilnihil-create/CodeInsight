#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>>a(h,vector<char>(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin >> a.at(i).at(j);
  vector<vector<int>>cost(h,vector<int>(w,100000));
  cost.at(0).at(0)=a.at(0).at(0)=='#';
  for(int i=1;i<h;i++)
    cost.at(i).at(0)=cost.at(i-1).at(0)+(a.at(i-1).at(0)=='.'&&a.at(i).at(0)=='#');
  for(int i=1;i<w;i++)
    cost.at(0).at(i)=cost.at(0).at(i-1)+(a.at(0).at(i-1)=='.'&&a.at(0).at(i)=='#');
  for(int i=1;i<h;i++){
    for(int j=1;j<w;j++){
      if(a.at(i-1).at(j)==a.at(i).at(j)||a.at(i).at(j-1)==a.at(i).at(j))
        cost.at(i).at(j)=min(cost.at(i-1).at(j)+(a.at(i-1).at(j)=='.'&&a.at(i).at(j)=='#'),cost.at(i).at(j-1)+(a.at(i).at(j-1)=='.'&&a.at(i).at(j)=='#'));
      else
        cost.at(i).at(j)=min(cost.at(i-1).at(j),cost.at(i).at(j-1))+(a.at(i-1).at(j)=='.'&&a.at(i).at(j)=='#');
    }
  }
  cout << cost.at(h-1).at(w-1) << endl;
  /*for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
    cout << cost.at(i).at(j);
    cout << '\n';
  }*/
  return 0;
}