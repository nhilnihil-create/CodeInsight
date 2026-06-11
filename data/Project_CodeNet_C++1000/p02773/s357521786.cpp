#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N;
string S[int(2e5+5)];
vector <string> ans;

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> S[i];
  sort(S, S + N);

  int M = 0, cnt = 1;
  for (int i = 1; i < N; i++){
    if (S[i] == S[i-1]){
      cnt++;
    }else{
      if (cnt > M){
        ans.clear();
        ans.push_back(S[i-1]);
      }else if (cnt == M){
        ans.push_back(S[i-1]);
      }
      M = max(M, cnt);
      cnt = 1;
    }
  }

  if (cnt > M){
    cout << S[N-1] << endl;
    return 0;
  }else if (cnt == M){
    ans.push_back(S[N-1]);
  }

  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;


  return 0;
}
