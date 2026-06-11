#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  long long k;
  cin >> k;
  char crr = s[0];
  long long cnt = 0;
  long long sum = 0;
  bool flag = true;
  int first_cnt = 0;
  int last_cnt = 0;
  for(int i = 1; i < s.length(); ++i){
    if(crr == s[i]) cnt++;
    else {
      if(flag){
        first_cnt = cnt;
        flag = false;
      }
      sum += (cnt + 1) / 2;
      crr = s[i];
      cnt = 0;
    }
  }
  if(cnt == s.length() - 1){
    cout << (cnt + 1) * k / 2 << endl;
    return 0;
  }
  sum += (cnt + 1) / 2;
  long long minus = 0;
  if(s[0] == s[s.length() - 1]){
    char temp = s[s.length() - 1];
    for(int i = s.length() - 2; i >= 0; --i){
      if(temp == s[i]) last_cnt++; 
      else break;
    }
    minus = ((first_cnt + 1) / 2 + (last_cnt + 1) / 2 - (first_cnt + last_cnt + 2) / 2) * (k - 1);
  }
  cout << sum * k - minus << endl;
}