#include <iostream>
#include <map>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  //入力終わり

  //各色のi番目までの登場回数
  //0で初期化
  int rn[N], gn[N], bn[N];
  rep(i, N){
    rn[i] = 0; gn[i] = 0; bn[i] = 0;
  }

  //各色のi番目までの登場回数を計算
  for(int i=0; i<N-1; i++){
    if(S[i] == 'R')
      rn[i]++;
    else if(S[i] == 'G')
      gn[i]++;
    else
      bn[i]++;
    rn[i+1] = rn[i];
    gn[i+1] = gn[i];
    bn[i+1] = bn[i];
  }
  //N番目は別で見る
  if(S[N-1] == 'R')
    rn[N-1]++;
  else if(S[N-1] == 'G')
    gn[N-1]++;
  else if(S[N-1] == 'B')
    bn[N-1]++;

  //各色に数字を割り当てる
  //あとで判定に使う
  map<char, int> m;
  m['R'] = 0; m['G'] = 1; m['B'] = 2;
  
  long long ans = 0;
  for(int i=0; i<N-2; i++){
    for(int j=i+1; j<N-1; j++){
      //条件1を満たさない
      if(S[i] == S[j])
	continue;
      
      int k = j+(j-i);
      //i番目のとj番目でRとGを選んだとき
      if(m[S[i] ] + m[S[j] ] == 1){
	//j+1番目以降のBの数を加算
	ans = ans + bn[N-1] - bn[j];
	//条件2を満たさない
	if(k<N && S[k] == 'B')
	  ans--;
      }
      //GB(上と同じ処理)
      else if(m[S[i] ] + m[S[j] ] == 3){
	ans = ans + rn[N-1] - rn[j];
	if(k<N && S[k] == 'R')
	  ans--;
      }
      //BR(上と同じ処理)
      else if(m[S[i] ] + m[S[j] ] == 2){
	ans = ans + gn[N-1] - gn[j];
	if(k<N && S[k] == 'G')
	  ans--;
      }
    }
  }

  //解答
  cout << ans << endl;

  return 0;
}
