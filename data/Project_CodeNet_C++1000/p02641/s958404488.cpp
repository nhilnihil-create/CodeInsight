//list index out of range エラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int X,N;
  int p;
  cin >> X >> N;
  vector<int> P(N);
  int find_X(int, vector<int>);
  rep1(i, N){
    cin >> p;
    P[i] = p;
  }
  

  cout << find_X(X, P);

  
}

int find_X(int x, vector<int> P){
  int tem1, tem2;
  bool flag;
  int vector_finder(vector<int>, int);

  rep1(i, 100){
    tem1 = x-i;
    tem2 = x+i;

    flag = vector_finder(P, tem1);

    if (!flag){
      return tem1;
    }
    flag = vector_finder(P, tem2);

    if (!flag){
      return tem2;
    }
  }
}

int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}