#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
using ll = long long;

int main(){
  double h,w,x,y;
  cin>>h>>w>>x>>y;
  double ans=h*w/2;
  printf("%.10f",ans);
  if(h/2==x&&w/2==y) cout<<" 1";
  else cout<<" 0";
}
