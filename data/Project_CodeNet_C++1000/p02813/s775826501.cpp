#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> nums, P, Q;

  for (int i = 0; i < N; i++){
    nums.push_back(i+1);
  }
  
  for (int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    P.push_back(tmp);
  }

  for (int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    Q.push_back(tmp);
  }

  int p=1, a=0, b=0;
  do{
    
    for (int i = 0; i < N; i++){
      if (nums[i] != P[i]){
        break;
      }
      if (i == N-1){
        a = p;
      }
    }

    for (int i = 0; i < N; i++){
      if (nums[i] != Q[i]){
        break;
      }
      if (i == N-1){
        b = p;
      }
    }
    p++;
  }while(next_permutation(nums.begin(), nums.end()));

  printf("%d\n", abs(a-b));
}
