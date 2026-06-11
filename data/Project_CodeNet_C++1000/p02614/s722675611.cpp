#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

// bit表現まではいいと思うが，答えがかすりもしない．原因も分からないし人のコードも理解できない．．．
// 2^12までの全パターンを考慮してしまっているので答えが合わない


int main() {
  ll H, W, K;
  cin >> H >> W >> K;
  //vector<ll> a(N);
  vector<vector<char>> data(H + 1, vector<char>(W + 1));
  ll ans = 0;

  for(ll i=1; i <=H; i++){  
    for(ll j=1; j<=W; j++){
      char tmp;
      cin >> tmp;
      data[i][j] = tmp;
    }
  }
  
  for (int tmp = 0; tmp < (1 << H+W); tmp++) {
    bitset<12> s(tmp);
    auto copy_data = data;

    for(ll i=0; i < 12; i++){//赤にするパターン
      
      if(s.test(i)){
        
        if(i<H){
          //行に対応
          for (ll j=1; j <= W; j++){
            copy_data[i+1][j] = 'R';
          }
        }

        if(H<= i){
          for (ll j=1; j <= H; j++){
            copy_data[j][i+1-H] = 'R';
          }
        }

      }     
    
    }
    
    // countする    
    ll count_sum = 0 ;
    for(ll i=1; i <=H; i++){  
      for(ll j=1; j<=W; j++){
        if (copy_data[i][j] =='#') count_sum++;
      }
    }
    if(count_sum == K){
      ans ++;
    }
       
  }
  cout << ans << endl;
  return 0;
}
