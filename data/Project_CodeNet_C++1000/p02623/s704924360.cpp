#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vector<int64_t> sa(n+1,0);
  vector<int64_t> sb(m+1,0);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    sa.at(i+1)=sa.at(i)+a;
  }
  for(int i=0;i<m;i++){
    int b;
    cin>>b;
    sb.at(i+1)=sb.at(i)+b;
  }
  int x=0;
  for(int i=n,j=0;i>=0;i--){
    if(sa.at(i)>k)
      continue;
    while(j+1<=m&&sa.at(i)+sb.at(j+1)<=k)
      j++;
    x=max(x,i+j);
  }
  cout<<x<<endl;
}