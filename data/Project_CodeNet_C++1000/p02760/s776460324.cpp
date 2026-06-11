#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<int>>	A(3,vector<int>(3));
  for(int i=0;i<3;i++){
    cin >> A.at(i).at(0) >> A.at(i).at(1) >> A.at(i).at(2);
  }
  
  int n;	cin >> n;
  for(int i=0;i<n;i++){
    int b;	cin >> b;
    for(int x=0;x<3;x++){
      for(int y=0;y<3;y++){
        if(A.at(x).at(y)==b)	A.at(x).at(y)=0;
      }
    }
  }
  
  for(int x=0;x<3;x++){
    if(A.at(x).at(0)==0&&A.at(x).at(1)==0&&A.at(x).at(2)==0){
      cout << "Yes";
      return 0;
    }
  }
  
  for(int x=0;x<3;x++){
    if(A.at(0).at(x)==0&&A.at(1).at(x)==0&&A.at(2).at(x)==0){
      cout << "Yes";
      return 0;
    }
  }
  
  if(A.at(0).at(0)==0&&A.at(1).at(1)==0&&A.at(2).at(2)==0){
    cout << "Yes";
    return 0;
  }
  if (A.at(0).at(2)==0&&A.at(1).at(1)==0&&A.at(2).at(0)==0){
    cout << "Yes";
    return 0;
  }else{
  	cout << "No";
}
  
}