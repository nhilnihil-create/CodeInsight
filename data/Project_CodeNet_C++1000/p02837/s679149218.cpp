#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> x(n,vector<int>(0)),y(n,vector<int>(0));
  int i,j;
  for(i=0;i<n;i++){
    cin >> a.at(i);
    for(j=0;j<a.at(i);j++){
      int k,l;
      cin >> k >> l;
      x.at(i).push_back(k);
      y.at(i).push_back(l);
      x.at(i).at(j)--;
    }
  }
  
  int s=1;
  for(i=0;i<n;i++){
    s *= 2;
  }
  
  int max=0;
  vector<int> bit(n,0);
  for(i=0;i<s;i++){
    int p=i;
    int count=0;
    for(j=0;j<n;j++){
      bit.at(j)=p%2;
      count += bit.at(j);
      p /= 2;
    }
    
    bool judge=true;
    for(j=0;j<n;j++){
      if(bit.at(j)==1){
        int k;
        for(k=0;k<a.at(j);k++){
          if(bit.at(x.at(j).at(k))!=y.at(j).at(k)){
            judge=false;
          }
        }
      }
    }
    if(judge){
      if(max<count){
        max=count;
      }
    }
  }
  
  cout << max << endl;
}