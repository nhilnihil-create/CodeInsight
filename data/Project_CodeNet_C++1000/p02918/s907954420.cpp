#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

void print_vector(vector<int> v){
  rep(i, sz(v)){
    cout << v[i] << " ";
  }
  cout << endl;
  return;
}

int main(){
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  int score = 0;

  rep(i, N-1){
    if(S[i]==S[i+1]) score++;
  }

  int ans = min(score+2*K, N-1);

  cout << ans << endl;

  return 0;
}
