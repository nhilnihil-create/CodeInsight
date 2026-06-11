#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N , M , K ;
  cin >> N >> M >> K ; 
  vector<int> A(N) , B(M) ;  
  
  for(int i = 0 ; i < N ; i++){
    cin >> A.at(i) ; 
  }
  for(int i = 0 ; i < M ; i++){
    cin >> B.at(i) ; 
  }
  
  int64_t T = 0 ; 
  for(int i = 0 ; i < M ; i++) T += B.at(i) ; //Bの机から全部読んだ時の時間
  int j = M ; //B机から全部読んだ札数
  int ans = 0 ; //最終的な答え
  
  for(int i = 0 ; i <= N ; i++){
    while ( j > 0 && T > K ){
      --j ; //机Bのj冊目の時間は配列Bのj-1個目(ゼロインデックスだから)
      T -= B.at(j) ; //M個目を読まないことにするのでその時間を減らす
    }
    if(T > K) break ; //机Bからj番目の本を読まなかった時、Kを超えたら何もせず終わり
    
    ans = max(ans , i+j) ; //一番多く読めた札数を残す
    
    if(i == N) break ;// 机AにはN冊までしかないので範囲外参照することになる
    
    T += A.at(i) ;// 机Aからi番目の本を読むのにかかる時間を足す
  }
  
  cout << ans << endl ; 
  
  
}