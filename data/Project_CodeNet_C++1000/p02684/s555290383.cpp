#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll N,K; cin >> N >> K;
  vector<ll> data(N+1); for(int i = 1;i<N+1;i++) cin >> data.at(i);
  int a=1,b=1; //循環を検出するための変数
  ll i = 0,ans = 1;
  int num = 0; //循環がスタートするまでの数と循環してる個数
  while(a != b || i ==0){//追いつくところを計算
    if(i > K){
      for(i = 0; i < K ; i++) ans = data[ans];
      cout << ans << endl;
      return 0;
    }
    a = data[a];
    b = data[data[b]];
    i++;
  }
  b = 1; i = 0;//早い方を最初の位置に戻して
  while(a != b){//ループ開始地点を算出
    a = data[a];
    b = data[b];
    i++; //ループまでの余計な移動数
  }
  K -= i; //ループまでの余計な移動分減らす
  ans = a; //ループの開始地点からスタートさせる
  while(a != b || num == 0){//ループ個数を算出
    a = data[a];
    b = data[data[b]];
    num++; 
  }
  for(i = 0; i < K % num; i++){//ループ回数で割った分だけ回す
    ans = data[ans];
  }
  cout << ans << endl;
}