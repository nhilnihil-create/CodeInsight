//コメント有りver
#include <bits/stdc++.h>
using namespace std;
using  P=pair<int,int>;
int main(){
  int N,T,dp[3020][6020],maxvalue=0,a,b;
  cin>>N>>T;
  vector<P> vec(0);
  for(int i=0;i<N;i++){
    cin>>a>>b;
    vec.push_back(make_pair(a,b));//a(first)は所要時間,b(second)は価値
  }
  //所要時間順にソート
  sort(vec.begin(),vec.end());
  //(1+(rock^価値)*x^(所要時間))の累積の考えて指数について制限をかけて考える
  //係数についてはrockの指数部分について見る。
  //形式的冪級数展開を行う(T+max(所要時間)まで考える)
  //計算量はO(N*(T+max(所要時間)))<=O(1.8*10^7)なので間に合う！
  for(int h=0;h<N;h++){
    //先に0乗の係数は1にしておく
    dp[h][0]=1;
  }
  for(int i=1;i<=N;i++){
    for(int j=0;j<T;j++){
      if(dp[i-1][j]!=0){//多項式をかける前のj乗の係数が0で無いなら
        //多項式のうちxの指数乗の方について、係数をまずは計算
        dp[i][j+vec.at(i-1).first]+=dp[i-1][j]+vec.at(i-1).second;
        //(jが0の時だけ処理(j=0の係数の1が加算されてしまうため))
        if(j==0){dp[i][j+vec.at(i-1).first]--;}
        //(j+vec.at(i-1).first)乗の係数はかける前の係数とかけて計算して出てきた二つのうち大きい方を採用
        dp[i][j+vec.at(i-1).first]=max(dp[i][j+vec.at(i-1).first],dp[i-1][j+vec.at(i-1).first]);
        //j乗の係数も二つのうち大きい方を採用
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
      }
      //最大価値を更新
      maxvalue=max(maxvalue,dp[i][j]);
      maxvalue=max(maxvalue,dp[i][j+vec.at(i-1).first]);
    }
  }
  cout<<maxvalue<<endl;
}