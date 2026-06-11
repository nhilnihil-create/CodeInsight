#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

ll sigu(ll a){
  ll ans = 0;
  REP(i,1,a + 1){
    ans += i;
  }
  return ans;
}

int main()
{
  ll ans = 0, cnt = 0, muki = 0, maenaga = -1;
  string s;

  cin >> s;

  ll n = s.length(), v[n+1];
  REP(i,0,n){
    if(s[i] == '<'){
      if(muki!=-1){
        ans += sigu(cnt) -cnt;
        if(maenaga > cnt)ans += maenaga;
        else ans += cnt;
        cnt=0;
        muki = -1;
      }
      cnt++;
    }else{
      if(muki!=1){
        ans += sigu(cnt) - cnt;
        maenaga = cnt;
        cnt=0;
        muki = 1;
      }
      cnt++;
    }
  }
  ans += sigu(cnt) - cnt;
  if(s[n-1]=='>'){
    if(maenaga > cnt)ans += maenaga;
    else ans += cnt;
  }else{
    ans += cnt;
  }
  cout << ans << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}