#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>

int init_BIT(std::vector<long long int> &BIT, int N_MAX);
int add_num(std::vector<long long int> &BIT, long long int N_MAX, long long int index, long long int d);
long long int cumulative_sum(std::vector<long long int> &BIT, long long int r);


int main(){
  
  // read problem
  long long int N, tmp;
  std::vector<long long int> S;
  
  scanf("%lld", &N);
  for(long long int i = 0; i < (1<<N); i++){
    scanf("%lld", &tmp);
    S.push_back(tmp);
  }
  
  // sort S
  std::sort(S.begin(), S.end(), std::less<long long int>() );
  
  /*std::cerr << "S:" << std::endl;
  for(long long int i = 0; i < (1<<N); i++){
    std::cerr << S[i] << " ";
  }std::cerr << std::endl << std::endl;*/
  
  // s[i] = maximum index j s.t. S[j] < S[i]
  long long int tmp1 = -1;
  std::vector<long long int> s;
  s.push_back(-1);
  for(long long int i = 1; i < (1<<N); i++){
    if(S[i] == S[i-1]){
      s.push_back(s[i-1]);
    }
    else{ // if(S[i] > S[i-1])
      s.push_back(i-1);
      //tmp = i-1;
    }
  }
  
  /*std::cerr << "s:" << std::endl;
  for(long long int i = 0; i < (1<<N); i++){
    std::cerr << s[i] << " ";
  }std::cerr << std::endl << std::endl;*/
  
  // prepare BIT

  long long int N_MAX = 1<<(N+1);
  
  std::vector<long long int> BIT;
  for(int i = 0; i < N_MAX; i++){
    BIT.push_back(0);
  }
  
  // solve problem
  std::vector<long long int> exist(1<<N);
  exist[(1<<N)-1] = 1;
  add_num(BIT, N_MAX, (1<<N)-1, 1);

  
  /*std::cerr << "initial exist:" << std::endl;
  for(long long int i = 0; i < (1<<N); i++){
    std::cerr << exist[i] << " ";
  }std::cerr << std::endl << std::endl;*/
  
  long long int possible = 1;
  long long int r, l, mid, d;
  for(long long int step = 1; step <= N; step++){
    tmp = 0;
    for(long long int i = (1<<N)-1; i >= 0; i--){
      // if the slime already exists
      if(exist[i] > 0 && exist[i] <= step){
        // if there is no smaller slime to produce
        if(cumulative_sum(BIT, s[i]) == s[i]+1){
          possible = 0;
          i = 0; step = N; // break
        }
        else{
          // search for the maximum slime to produce
          if(exist[s[i]] == 0){
            //std::cerr << "s" << std::endl;
            r = s[i];
          }
          else{
            //bisection
            //std::cerr << "bisection" << std::endl;
            d = s[i] - cumulative_sum(BIT, s[i]);
            l = -1;
            r = s[i];
            while(r-l > 1){
              mid = (l+r)/2;
              if(mid - cumulative_sum(BIT, mid) == d) r = mid;
              else l = mid;
            }
          }
          // produce l-th slime
          add_num(BIT, N_MAX, r, 1);
          
          exist[r] = step+1;
          tmp++;
          /*std::cerr << "tmp = " << tmp << std::endl;
          
          std::cerr << i << "-th slime of size " << S[i] << " produces " << r << "-th slime of size" << S[r] << std::endl;
          
          std::cerr << "current exist:" << std::endl;
          for(long long int i = 0; i < (1<<N); i++){
            std::cerr << exist[i] << " ";
          }std::cerr << std::endl << std::endl;
          std::cerr << "cumulative sum" << std::endl;
          for(long long int i = 0; i < (1<<N); i++){
            std::cerr << cumulative_sum(BIT, i) << " ";
          }std::cerr << std::endl;*/

          
          // if i-th step is done
          if(tmp == (1<<step)){
            break;
          }
        }
      }
    }
  }
  
  /*std::cerr << "current exist:" << std::endl;
  for(long long int i = 0; i < (1<<N); i++){
    std::cerr << exist[i] << " ";
  }std::cerr << std::endl << std::endl;*/
  
  std::cerr << "Answer:" << std::endl;
  if(possible){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }
  
  
  return 0;
}

/*int init_BIT(std::vector<long long int> &BIT, long long int N_MAX){
  for(int i = 0; i < N; i++){
    BIT[i];
  }
}*/

int add_num(std::vector<long long int> &BIT, long long int N_MAX, long long int index, long long int d){
  index ++;
  while(index < N_MAX){
    BIT[index-1] += d;
    index += (index & -index);
  }
  
  return 0;
}

long long int cumulative_sum(std::vector<long long int> &BIT, long long int r){
  // sum of no elements
  if(r == -1){
    return 0;
  }
  
  r++;
  long long int sum = 0;
  while(r > 0){
    sum += BIT[r-1];
    r -= (r & -r);
  }
  
  return sum;
}
