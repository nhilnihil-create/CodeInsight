#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,ans,sum,fix;
int two[100],v[123456];

signed main(){
  two[0]=1;for(int i=1;i<100;i++)two[i]=two[i-1]*2;
  cin>>n;
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=0;i<n;i++)sum^=v[i];
  for(int i=0;i<n;i++)v[i]&=(~sum);
  for(int i=59;i>=0;i--){
    bool f=false;
    for(int j=fix;j<n&&!f;j++) if(v[j]&two[i]) f=true,swap(v[fix++],v[j]);
    if(f) for(int j=0;j<n;j++) if((v[j]&two[i])&&(j!=fix-1)) v[j]^=v[fix-1];
  }
  for(int i=0;i<n;i++)ans^=v[i];
  cout<<ans*2+sum<<endl;
}

/*
解説AC
maspyさんの記事がわかりやすかった
吐き出し方の気持ちを全く理解していなかったのでしっかり頑張ろう　オエ〜
*/
