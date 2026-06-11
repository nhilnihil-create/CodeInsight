#include<bits/stdc++.h>
using namespace std;
vector<int> c,d;
vector<vector<int>> a;
int n,m,x,sum=0,res=1200001;
int search(int cnt){
  if(cnt>=n) {
    bool solve=true;
    --cnt;
    for(int i=0; i<m; ++i) solve&=(d[i]>=x);
    if(solve==true) return sum; else return res;
  }
  for(int i=0; i<2; ++i){
    if(i==1) {sum+=c[cnt]; for(int j=0; j<m; ++j) d[j]+=a[cnt][j];}
    res=min(res,search(cnt+1));
  }
  for(int i=0; i<m; ++i) d[i]-=a[cnt][i];
  sum-=c[cnt];
  if(cnt==0&&res==1200001) return -1; else return res;
}

int main(void){
  cin>>n>>m>>x;
  c.resize(n); d.resize(m);
  a.resize(n); for(int i=0; i<n; ++i) a[i].resize(m);
  for(int i=0; i<n; ++i){
    cin>>c[i];
    for(int j=0; j<m; ++j) cin>>a[i][j];
  }
  cout<<search(0)<<endl;
  return 0;
}
