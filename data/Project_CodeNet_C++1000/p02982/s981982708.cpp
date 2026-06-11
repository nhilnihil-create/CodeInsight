#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  vector<int> sq(128);
  int i,j,k;
  for(i=0;i<128;i++){
    sq.at(i)=i*i;
  }
  
  int n,d;
  cin >> n >> d;
  vector<vector<int>> x(n,vector<int>(d,0));
  for(i=0;i<n;i++){
    for(j=0;j<d;j++){
      cin >> x.at(i).at(j);
    }
  }
  
  int s=0,dis2;
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      dis2=0;
      for(k=0;k<d;k++){
        dis2 += (x.at(i).at(k)-x.at(j).at(k))*(x.at(i).at(k)-x.at(j).at(k));
      }
      for(k=0;k<128;k++){
        if(dis2==sq.at(k)){
          s++;
        }
      }
    }
  }
  
  cout << s << endl;
}