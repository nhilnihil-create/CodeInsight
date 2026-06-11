#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define mp make_pair

const int N = 1e6 + 5;

int dp[N];

int get(string s){

  int n = s.size() - 1;
  int ret = 0;
  for(int r = 0; r <= n; r++){
    int nr = n - r;
    int now = s[r] - '0';
    now %= 2;
    if(now && ((nr & r) == 0))ret ^= 1;
  }
  return ret;
}

int main() {

  int n;
  cin >> n;
  string s;
  cin >> s;

  for(int i = 0; i < n; i++)s[i]--; 

  int w = get(s);
  if(w & 1)cout << 1 << endl;
  else {
    for(int i = 0; i < n; i++){
      if(s[i] == '1'){
        cout << 0 << endl;
        return 0;
      }
    }
    for(int i = 0; i < n; i++)s[i] = '0' + (s[i] - '0')/2;
    if(get(s))cout << 2 << endl;
    else cout << 0 << endl;
  }

  return 0;
}