#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> coordinate(n);
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    coordinate[i].first=x;
    coordinate[i].second=y;
  }
  sort(coordinate.begin(),coordinate.end());
  long double ans=0;
  long long cnt=1;
  for(int i=n;i>=1;i--)cnt*=i;
  do{
    for(int i=0;i<n-1;i++){
      long long a=coordinate[i+1].first-coordinate[i].first;
      long long b=coordinate[i+1].second-coordinate[i].second;
      ans+=sqrt(a*a+b*b);
    }
  }while(next_permutation(coordinate.begin(),coordinate.end()));
  cout<<fixed<<setprecision(10)<<ans/cnt<<endl;
  return 0;
}