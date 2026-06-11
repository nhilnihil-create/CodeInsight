#include<bits/stdc++.h>
using namespace std;

int N;
vector<long long> x,y;

int main(){
  cin >> N;
  x.resize(N);
  y.resize(N);
  
  for(int i =0; i < N; i++){
    cin >> x[i] >> y[i]; 
  }
  
  int res =N; //最大コストはN - 1(0-index)  + 必ずかかる1でN
  if(N == 1) cout << "1" << endl;
  else{
    for(int i =0; i < N; i++){ //1つ目の点xi,yiを見る。N通り繰り返す。
      for(int j = 0; j < N; j++){ //1つ目の点に対し、残るすべての点xj,yjを見る。ここまででO(N^2)
        if( i == j ) continue; //i==jのときは制約によりないので除外する
        long long dx = x[j] - x[i];
        long long dy = y[j] - y[i]; //2点から移動ベクトルを算出
        
        int count =0; //コストが0で済む数を数え上げる
        
        //dx,dyは(p,q)。よってそれぞれの点(p,q)においてさらに
        for(int i2 = 0; i2 <N; i2++){ //ひとつめの点がxi,yiのとき
          for(int j2 =0; j2 < N; j2++){ //残りの点xj,yj の組み合わせを全て調べる
            if(i == j )continue;
            if(dx == x[j2]- x[i2] && dy == y[j2]- y[i2])count++; //j2,i2の差がdx,dyに等しければ0コスト
          }
        }
        res = min(res, N - count); //コストが0で済んだ回数をNから引く。すべてのパターンで調べ、一番小さかったものを残す
        
      }
    }
      cout << res << endl;
    
  }

}