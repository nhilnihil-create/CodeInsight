//list index out of range エラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int N;
  int p;
  cin >> N;
  vector<int> P(N);
  rep1(i, N){
    cin >> p;
    P[i] = p;
  }
  
  int max_a = *max_element(P.begin(),P.end());
  vector<bool> Era(max_a + 1);
  rep1(i, max_a + 1){
    Era[i] = true;
  }

  sort(P.begin(), P.end());
  rep1(i, N-1){
    if(P[i] == P[i+1]){
      Era[P[i]] = false;
    }
  }

  int tem;
  rep1(i, N){
    tem = P[i];
    int c = max_a / tem;
    rep1(i, c-1){
      Era[tem * (i+2)] = false;
    }
    
  }

  int ans = 0;
  rep1(i, N){
    if(Era[P[i]] == true){
      ans += 1;
    }
  }
  
  cout << ans;
  
}

