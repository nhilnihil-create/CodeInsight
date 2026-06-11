#include <iostream>
#include <vector>

int main(){
  const int max = 20, min = 0;
  int N;
  std::cin >> N;
  std::vector<std::vector<unsigned long int> > dp(N - 1,std::vector<unsigned long int>(max \
+ 1,0));
  std::vector<int> num(N);

  for(int i = 0; i < N; ++i){
    std::cin >> num[i];
  }
  //１項目を反映                                                                            
  ++dp[0][num[0]];

  for(int i = 0; i < N - 2; ++i){
    for(int j = 0; j < max + 1; ++j){
      //次項を足した場合                                                                    
      if(j + num[i + 1] <= max){
        dp[i + 1][j + num[i + 1]] += dp[i][j];
      }
      //次項を引いた場合                                                                    
      if(j - num[i + 1] >= min){
        dp[i + 1][j - num[i + 1]] += dp[i][j];
      }
    }
  }
  std::cout << dp[N - 2][num[N-1]] << std::endl;
  return 0;
}