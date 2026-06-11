#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int N;
string moji = "abcdefghijklmnopqrstuvwxyz";
void dfs(string s, int num, int mx){
  s.push_back(moji[num]);
  if (s.size() == N){
    cout << s << endl;
  }else{
    rep(i, mx + 2){
      dfs(s, i, max(i, mx));
    }
  }
}

int main(){
  cin >> N;
  string s;
  dfs(s, 0, 0);
}
  