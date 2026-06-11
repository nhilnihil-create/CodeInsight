#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG



int main() {
  ll N, R;
  cin >> N >> R;
  
  if(N>=10){
    cout << R << endl;
  }else{
    cout << R + 100 * (10 - N) << endl;
  }


  return 0;
}
