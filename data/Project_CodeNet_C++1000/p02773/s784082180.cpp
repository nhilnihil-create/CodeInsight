#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
    ll N;
    cin >> N;
    map<string, ll> memo;
    for (int i = 0; i < N; i++){
      string s;
      cin >> s;
      memo[s] += 1;
    }
    ll maxv = 0;
    for(auto a: memo){
      ll v = a.second;
      if (v > maxv) maxv = v;
    }
    for (auto it = memo.begin(); it != memo.end(); it++){
      if (it->second == maxv) cout << it->first << endl;
    }
    return 0;
}