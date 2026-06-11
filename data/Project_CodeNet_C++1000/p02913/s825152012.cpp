#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N;
  string S;
  cin>>N>>S;
  int ans = 0;
  for(int t = 0; t < N; t++){
    vector<int> Z(N-t);
    Z[0] = N-t;
    int i = 1, j = 0;
    while(i < N-t){
      while(i + j < N-t && S[j+t] == S[i + j+t]) j++;
      Z[i] = j;

      if(j == 0){
        i++;
        continue;
      }
      int k = 1;
      while(k < j && k + Z[k] < j){
        Z[i + k] = Z[k];
        k++;
      }
      i += k;
      j -= k;
    }
    for(int l = 0; l < (int)Z.size();l++) chmax(ans,min(Z[l],l));
  }
  cout<<ans<<endl;
}