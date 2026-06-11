#include<bits/stdc++.h>
using namespace std;
typedef long long ll;  //long longでゴリ押しします

vector<vector<ll>> alpha(26, vector<ll>());  //各alphabetの位置
string s, t;
bool able = true;
ll res = 0;

ll binary_search(ll n, ll l, ll r, ll val){  //valより大きいa
  if(l == r) return l;

  ll c = (r-l)/2 + l;
  if(alpha[n][c] <= val) return binary_search(n, c+1, r, val);
  else if(alpha[n][c] > val) return binary_search(n, l, c, val);

}

ll search_next(ll rda, ll t_pre){  //alpha[rda]内で最もpreと近い番号を返す
  ll len = alpha[rda].size(), num;
  if(len == 0) return -1;  //そもそも作れない
  if(alpha[rda][len-1] <= t_pre) return alpha[rda][0];  //preが大きい ->次の文字列最初出現文字
  num = binary_search(rda, 0, len-1, t_pre);

  return alpha[rda][num];
}
  

int main(){
  cin >> s >> t;

  ll Rda;  //aとの相対距離
  for(int i = 0; i < s.size(); i++){
    Rda = s[i] - 'a';
    alpha[Rda].push_back(i);
  }

  ll tRda, next;  //nextは次の文字の位置
  ll prev = -1;  //前回の文字位置 初期は-1
  for(int i = 0; i < t.size(); i++){
    tRda = t[i] - 'a';
    ll next = search_next(tRda, prev);
    if(next < 0){ able = false; break; }  //存在しない
    else {
      if(next > prev) res += next - prev;
      else res += (s.size() - prev) + next;
      prev = next;
    }
  }

  if(able) cout << res << endl;
  else cout << -1 << endl;

  return 0;
}

