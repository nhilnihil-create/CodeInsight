#include <bits/stdc++.h>
using namespace std;

int d[323456];//d[i]:i個のグループの数
int dwa[323456];//dwa[i]:sum[0,i) of d
int dkwa[323456];//dkwa[i]:sum[0,i) of k*d[k]
int f[323456];//f[i]:i個列を作るときの最大長さ
//=( sum[0,i)k*d[k] + i*sum[i,INF)*d )/i
//=( dkwa[i]+i*(dwa[INF]-dwa[i]) )/i

signed main(){
  int n;cin>>n;
  map<int,int> m;
  for(int i=0;i<n;i++){
    int a;cin>>a;
    m[a]++;
  }
  for(auto p:m)d[p.second]++;
  for(int i=0;i<323400;i++)dwa[i+1]=dwa[i]+d[i];
  for(int i=0;i<323400;i++)dkwa[i+1]=dkwa[i]+i*d[i];
  for(int i=1;i<323400;i++)f[i]=(dkwa[i]+i*(dwa[323300]-dwa[i]))/i;
  int now=n;
  for(int i=1;i<=n;i++){
    while(now&&f[now]<i)now--;
    cout<<now<<endl;
  }
}

/*
解説AC
えーこれは解けた気がするけど解説見るまで全く思いつかなかったな
考え方としては二分探索に近い
x個列を作るとしたときの寄与度を考える
見方をちょうど90度だけ変えて考えてあげるのは流石に典型
*/