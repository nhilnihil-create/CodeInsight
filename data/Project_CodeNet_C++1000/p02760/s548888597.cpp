#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>>retu(8,vector<int>(3));
  vector<vector<int>>card(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> card.at(i).at(j);
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      retu.at(i).at(j)=card.at(i).at(j);
      retu.at(i+3).at(j)=card.at(j).at(i);
    }
    retu.at(6).at(i)=card.at(i).at(i);
    retu.at(7).at(i)=card.at(2-i).at(i);
  }
  //for(int i=0;i<8;i++)
    //cout << retu.at(i).at(0) << ","<< retu.at(i).at(1) << "," << retu.at(i).at(2) << endl;
  map<int,int>deta;
  int n,b;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> b;
    deta[b]=1;
  }
  bool ans=false;
  for(int i=0;i<8;i++){
    if(deta[retu.at(i).at(0)]==1&&deta[retu.at(i).at(1)]==1&&deta[retu.at(i).at(2)]==1)
      ans=true;
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}