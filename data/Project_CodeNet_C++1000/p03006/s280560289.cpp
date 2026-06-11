#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int m=0;
  map<pair<int,int>,int> ma;
  int vec[n][2];
  for(int i=0;i<n;i++){
    cin>>vec[i][0]>>vec[i][1];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) continue;
      int a,b;
      a=vec[i][0]-vec[j][0];
      b=vec[i][1]-vec[j][1];
      pair<int,int> p=make_pair(a,b);
      ma[p]++;
      m=max(m,ma[p]);
    }
  }
  cout<<n-m<<endl;
}