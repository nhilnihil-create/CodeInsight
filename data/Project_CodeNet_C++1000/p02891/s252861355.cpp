#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  string S;
  long long K;
  cin >> S >> K;
  // 入力終了
  int N = S.size();
  string copy = S;
  
  // 全て同じ文字で構成されているなら，1つ飛ばしで変えていけばOK 
  bool all_same = true;
  rep(i, N-1)
    all_same *= (S[i] == S[i+1] );
  if(all_same){
    cout << N*K/2 << endl;
    return 0;
  }
  
  long long ans = 0;
  for(int i=1; i<N; i++){
    // 1つ前と同じなら，i番目を *(任意の文字)で置き換える
    if(S[i-1] == S[i] ){
      S[i] = '*';
      ans++;
      // 3つ連続するときは中央を変更すると考えて，indexを1つ先送り
      if(i<N-1 && S[i] == S[i+1] )
	i++;
    }
  }

  // 上の処理の後，先頭と末尾が同じなら繋ぎ目をK-1回書き換える
  // ただし，先頭から続く同じ文字の文字列長と，末尾からのそれの偶奇が
  // 一致しなければうまいこと調整できる
  long long tmp = 0;
  if(copy[0] == copy[N-1]){
    int l=0, r=N-2;
    while(copy[l] == copy[l+1])
      l++;
    while(copy[r] == copy[r+1])
      r--;
    if((l+1)%2 == (N-r-1)%2)
      tmp = K-1;
  }
  
  // 解答
  cout << ans*K + tmp << endl;

  return 0;
}
