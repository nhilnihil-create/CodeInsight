#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<int>> bingo(3,vector<int> (3));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin>>bingo.at(i).at(j);
    }
  }
  int n;
  cin>>n;
  vector<int> b(n);
  for(int i=0; i<n; i++){
    cin>>b.at(i);
  }
  vector<vector<bool>> ans(3,vector<bool> (3,false));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      for(int k=0; k<n; k++){
        if(bingo.at(i).at(j)==b.at(k)){
          ans.at(i).at(j)=true;
        }
      }
    }
  }
  string s="No";
  for(int i=0; i<3; i++){
    if(ans.at(0).at(i)&&ans.at(1).at(i)&&ans.at(2).at(i)) s="Yes";
    else if(ans.at(i).at(0)&&ans.at(i).at(1)&&ans.at(i).at(2)) s="Yes";
  }
  if(ans.at(0).at(0)&&ans.at(1).at(1)&&ans.at(2).at(2)) s="Yes";
  if(ans.at(0).at(2)&&ans.at(1).at(1)&&ans.at(2).at(0)) s="Yes";
  cout<<s<<endl;
}