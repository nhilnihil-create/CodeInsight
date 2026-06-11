#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  string s;
  cin >> s;
  ll k;
  cin >> k;
  ll cnt1=0;
  ll cnt2=0;
  ll cnt=0;
  int n=s.size();
  for(int i=0;i<n;++i){
    if(s[0]==s[i]) cnt++;
  }
  if(n==cnt){
    cout << (n*k)/2 << endl;
    return 0;
  }

  string t=s+s;
  for(int i=0;i<n;++i){
    if(s[i]==s[i+1]){
      s[i+1]='#';
      cnt1++;
    }
  }

  for(int i=0;i<2*n;++i){
    if(t[i]==t[i+1]){
      t[i+1]='#';
      cnt2++;
    }
  }
  //cout << cnt2 << endl;
  cout << cnt1+(cnt2-cnt1)*(k-1) << endl;
  return 0;

}
