#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
const ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  bool p[n];
  rep(i,0,n){
    int a,b;
    cin>>a>>b;
    p[i]=(a==b);
  }
  int cur=0;
  int m=0;
  rep(i,0,n){
    if(p[i]) cur++;
    else cur=0;
    m=max(m,cur);
  }
  if(m>=3) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}