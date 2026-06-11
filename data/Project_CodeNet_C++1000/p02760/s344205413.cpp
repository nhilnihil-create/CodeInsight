#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> a(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>a.at(i).at(j);
    }
  }
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int b;
    cin>>b;
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(b==a.at(j).at(k)) a.at(j).at(k)*=0;
      }
    }
  }
  if(a.at(0).at(0)==0&&a.at(0).at(1)==0&&a.at(0).at(2)==0) cout<<"Yes"<<endl;
  else if(a.at(1).at(0)==0&&a.at(1).at(1)==0&&a.at(1).at(2)==0) cout<<"Yes"<<endl;
  else if(a.at(2).at(0)==0&&a.at(2).at(1)==0&&a.at(2).at(2)==0) cout<<"Yes"<<endl;
  else if(a.at(0).at(0)==0&&a.at(1).at(0)==0&&a.at(2).at(0)==0) cout<<"Yes"<<endl;
  else if(a.at(0).at(1)==0&&a.at(1).at(1)==0&&a.at(2).at(1)==0) cout<<"Yes"<<endl;
  else if(a.at(0).at(2)==0&&a.at(1).at(2)==0&&a.at(2).at(2)==0) cout<<"Yes"<<endl;
  else if(a.at(0).at(0)==0&&a.at(1).at(1)==0&&a.at(2).at(2)==0) cout<<"Yes"<<endl;
  else if(a.at(0).at(2)==0&&a.at(1).at(1)==0&&a.at(2).at(0)==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}