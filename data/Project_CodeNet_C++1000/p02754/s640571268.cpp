#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG




int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  

  ll tmp1, tmp2, ans;

  tmp1 = N / (A+B);
  tmp2 = N % (A+B);


  if(tmp2 < A ){
    ans = tmp1 * A + tmp2;
  }else{
    ans = tmp1 * A + A;
    
  }

  cout << ans <<endl;


  return 0;
}
