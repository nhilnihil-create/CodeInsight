#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

int GCD(int A, int B){
  if (A < B) swap(A, B);
  while (A % B != 0){
    A %= B; swap(A, B);
  }
  return B;
}

bool Judge_Prime(int num){
  if (num == 1) return false;
  for (int i = 2; i * i <= num; i++){
    if (num % i == 0) return false;
  }
  return true;
}

int N, A[int(1e6+5)];
vector <int> Prime = {2};
map <int, bool> used;

int main(){
  for (int i = 3; i <= 1e3; i += 2){
    if (Judge_Prime(i)) Prime.push_back(i);
  }

  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  int G = A[0];
  for (int i = 0; i < N; i++) G = GCD(G, A[i]);

  if (G > 1){
    cout << "not coprime" << endl;
    return 0;
  }

  for (int i = 0; i < N; i++){
    int num = A[i];
    for (int j : Prime){
      if (num % j != 0) continue;
      if (used[j]){
        cout << "setwise coprime" << endl;
        return 0;
      }
      used[j] = true;
      while (num % j == 0) num /= j;
    }
    if (num > 1){
      if (used[num]){
        cout << "setwise coprime" << endl;
        return 0;
      }
      used[num] = true;
    }
  }

  cout << "pairwise coprime" << endl;

  return 0;
}
