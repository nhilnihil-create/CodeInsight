#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

long long tmpmax(vector<long long>s, int n){
  long long tmpmax = -1e9;
  rep(i,n){
    tmpmax = max(tmpmax, s.at(i));
  }
  return tmpmax;
}

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> P(N), C(N);
  rep(i,N){
    cin >> P.at(i);
  }
  rep(i,N){
    cin >> C.at(i);
  }
  long long ans = -1e9;
  rep(i,N){
    vector<long long> s(N);
    long long score = 0;
    int oldi = i, x = N;
    rep(j,N){
      int newi = P.at(oldi) - 1;
      score += C.at(newi);
      s.at(j) = score;
      oldi = newi;
      if(newi==i){
        x = min(x, j+1);
        break;
      }
    }
    if(score>0){
      ans = max(ans, score*(K/x)+tmpmax(s, K%x));
      ans = max(ans, score*(K/x-1)+tmpmax(s, x));
    }else{
      ans = max(ans, tmpmax(s, x));
    }
  }
  cout << ans;
  return 0;
}