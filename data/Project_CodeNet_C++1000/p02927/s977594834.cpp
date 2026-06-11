#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;

int main(){
  int m,d;
  cin>>m>>d;
  int ans=0;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=d;j++){
      int d1=j%10;
      int d2=j/10;
      if(d1>1&&d2>1&&i==d1*d2)ans++;
    }
  }
  cout<<ans<<endl;
  return(0);
}
