//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#include <list>

int main(){
  int n,m;
  long long k;
  list<long long> A(0), B(0);
  long long imp;
  cin >> n >> m >> k;
  rep1(i, n){
    cin >> imp;
    A.push_back(imp);
  }
  rep1(i, m){
    cin >> imp;
    B.push_back(imp);
  }

  long long now = accumulate(A.begin(), A.end(), 0LL);
  while(now > k){
    now -= A.back();
    A.pop_back();
  }
  now = accumulate(B.begin(), B.end(), 0LL);
  while(now > k){
    now -= B.back();
    B.pop_back();
  }

  int tem = A.size();
  int max = A.size();
  int count = B.size();
  now = accumulate(A.begin(), A.end(), 0LL);
  rep1(i, count){
    A.push_front(B.front());
    tem += 1;
    now += B.front();
    B.pop_front();

    while(!A.empty() && now > k){
      now -= A.back();
      A.pop_back();
      tem -= 1;
    }

    if(tem > max){
      max = tem;
    }
    
  }
  
  cout << max;
 
}