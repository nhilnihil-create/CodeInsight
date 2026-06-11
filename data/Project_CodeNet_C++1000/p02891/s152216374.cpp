#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;
//階乗できるよ
ll kaizyo(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  string s; cin >> s;
  ll k; cin >> k;
  ll count = 0;

  int size_s = s.size();

  if(size_s == 1) {
    count = floor(k / 2);
    cout << count << endl;
    return 0;
  }

  if(s.at(0) == s.at(size_s - 1)) {
    ll count_front_same_num = 1, count_back_same_num = 1;
    bool flag1 = false;
    rep(i,size_s) {
      if(i == 0) continue;
      if(s.at(i) == s.at(i - 1)) {
        count_front_same_num++;
      }
      else{
        flag1 = true;
        break;
      }
    }

    if(flag1) {
      for(int i = size_s - 1; i > 0; i--){
        if(s.at(i) == s.at(i - 1)) {
          count_back_same_num++;
        }
        else {
          break;
        }
      }      
    }

    if(!flag1) {
      count = floor(k * size_s / 2);
      cout << count << endl;
      return 0;
    }

    rep(i,size_s) {
      if(i == 0) continue;
      if(s.at(i) == s.at(i - 1)) {
        s.at(i) = '*';
        count++;
        //cout << i << endl;
      }
    }

    count = count * k;

    count = count - (floor(count_front_same_num / 2) + floor(count_back_same_num / 2) - floor((count_front_same_num + count_back_same_num) / 2)) * (k - 1);
    cout << count << endl;
    return 0;
  }

  rep(i,size_s) {
    if(i == 0) continue;
    if(s.at(i) == s.at(i - 1)) {
      s.at(i) = '*';
      count++;
      //cout << i << endl;
    }
  }

  count = count * k;


  cout << count << endl;
  //cout << s << endl;
}

