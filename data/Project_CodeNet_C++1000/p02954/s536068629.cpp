#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;

//階乗関数　ATCODER_AMARIに注意
ll factorial(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    //sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  string s; cin >> s;
  ll sizeofs = s.size();
  ll count = 0;
  bool flag = true;
  vector<ll> ans(sizeofs,0);
  ll tmp = 0;
  
  rep(i,sizeofs) {
    char current = s.at(i);
    
    if(flag) {
      if(current == 'L') {
        //cout << i << ' ' << count << endl;
        ans.at(i - 1) += count / 2;
        ans.at(i) += count / 2;
        if(count % 2 != 0) ans.at(i - 1)++;
        count = 0;
        flag = false;
        tmp = i;
        if(i == sizeofs - 1) {
          ans.at(i)++;
        }
      }
    }
    else if(!flag) {
      if(current == 'R') {
        //cout << i << ' ' << count << endl;
        ans.at(tmp) += count / 2;
        ans.at(tmp - 1) += count / 2;
        if(count % 2 != 0) ans.at(tmp)++;
        count = 0;
        flag = true;
      }
      else if(i == sizeofs - 1) {
        count++;
        //cout << i << ' ' << count << endl;
        ans.at(tmp) += count / 2;
        ans.at(tmp - 1) += count / 2;
        if(count % 2 != 0) ans.at(tmp)++;
      }
      //cout << i << endl;
    }

    count++;
  }

  rep(i,sizeofs) cout << ans.at(i) << ' ';
  cout << endl;
}
