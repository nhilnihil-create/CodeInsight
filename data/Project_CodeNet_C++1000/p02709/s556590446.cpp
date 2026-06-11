#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 子どもを表す構造体
struct infant{
  int position; // 位置
  int64_t lively;   // 活発度
  
  // 活発度が同じ場合、位置で判断する
  bool operator<( const infant &right ) const{
    return lively == right.lively ? position < right.position : lively < right.lively;
  }
  
};

int main(){
  
  int N = 0;
  std::cin >> N;
  
  std::vector< infant > vec_infants( N );
  for( int cnt = 0; cnt < N; cnt++ ){
    vec_infants.at( cnt ).position = cnt + 1;
    std::cin >> vec_infants.at( cnt ).lively;
  }
  
  // 活発度を基準に降順ソート
  sort( vec_infants.begin(), vec_infants.end() );
  reverse( vec_infants.begin(), vec_infants.end() ); 
  
  // dp[x][y]
  // x:左端に寄せた数 y:右端に寄せた数
  // x+y = N
  std::vector< std::vector< int64_t > > dp( N + 1, std::vector< int64_t >( N + 1, 0 ) );
  for( int i = 0; i < N; i++ ){
    for( int j = 0; j < N - i; j++ ){
      // 左端に寄せたとき
      int left_renge = std::abs( ( i + 1 ) - vec_infants.at( i + j ).position );
      if( dp.at( i + 1 ).at( j ) < dp.at( i ).at( j ) + vec_infants.at( i + j ).lively * left_renge ){
        dp.at( i + 1 ).at( j ) = dp.at( i ).at( j ) + vec_infants.at( i + j ).lively * left_renge;
      }
      // 右端に寄せたとき
      int right_renge = std::abs( ( N - j ) - vec_infants.at( i + j ).position );
      if( dp.at( i ).at( j + 1 ) < dp.at( i ).at( j ) + vec_infants.at( i + j ).lively * right_renge ){
        dp.at( i ).at( j + 1 ) = dp.at( i ).at( j ) + vec_infants.at( i + j ).lively * right_renge;
      }
      
    }
  }
  
  int64_t answer = 0;
  for(int i = 0; i <= N ;i++){
    for(int j = 0; j <= N; j++){
      answer = std::max( dp.at( i ).at( j ), answer );
    }
  }
  
  std::cout << answer << std::endl;
  
  return 0;
}
