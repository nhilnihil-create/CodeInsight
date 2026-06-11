#include <iostream>
#include <queue>

using namespace std;

int d[10010]={0};//最初に訪問した時刻を入れるタイムスタンプ
int f[10010]={0};//vの隣接リストを調べ終えた時刻のタイムスタンプ

int back[10010]={0};//番号nのもときた街番号をいれる

int g[1001][1001]={{0}};//要素を0で初期化
int timestamp = 1;
int number;
int dfs(int cur){
  d[cur]= timestamp;
  timestamp += 1;
  for(int dst = 0; dst < number; dst++){
    if(g[cur][dst]==1 && d[dst]==0){
      // d[dst]=timestamp;
      back[dst]=cur;
      dfs(dst);
    }
  }
  // timestamp += 1;
  // cout << "f[cur]" <<f[cur]<<"timestamp"<<timestamp<<"cur"<<cur<<endl;
  // abort();
  if(timestamp > number*2){
    return 0;
  }
  // cout << "f[cur]" <<f[cur]<<"timestamp"<<timestamp<<"cur"<<cur<<endl;
  // abort();
  f[cur]=timestamp;
  timestamp++;
}
void ans(int n){
  for (int i = 0; i < n; ++i)
  {
    cout << i+1 << " " << d[i] <<" "<< f[i] <<endl;
  }
}

int main(){
  // int g[1001][1001]={{0}};//要素を0で初期化
  int n,a,b,c;
  cin >> n;
  number = n;
  for (int i = 0; i < n; ++i)
  {
    cin >> a >> b ;
    for (int i = 0; i < b; ++i)
    {
      cin >> c;
      g[a-1][c-1]=1;/* code */
    }
  }
  d[0]=1;
  dfs(0);
  for (int i = 0; i < number; ++i)
  {
    if(d[i]==0){
      d[i]=timestamp;
      dfs(i);
    }
  }
  // for (int i = 0; i < number; ++i)
  // {
  //   cout << back[i]<<" ";
  // }

  ans(n);
}