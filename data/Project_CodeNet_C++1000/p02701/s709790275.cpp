#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

vector<string> S;

int main(){
  int N;
  cin >> N;
  string s;
  rep(i, N){
    cin >> s;
    S.push_back(s);
  }
  sort(S.begin(), S.end());
  S.erase(unique(S.begin(), S.end()), S.end());
  cout << S.size() << endl;
}
