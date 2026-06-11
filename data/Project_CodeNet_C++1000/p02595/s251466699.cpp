//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int n,d;
  cin >> n >> d;
  int a,b;
  int count = 0;
  rep1(i, n){
    cin >> a >> b;
    if(sqrt(pow(a,2) + pow(b,2)) <= d){
      count += 1;
    }
  }
  cout << count;
}