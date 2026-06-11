#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  int cnt1=0, cnt2=0;
  string s;
  cin >> s;
  rep(i, s.size()){
    if(i%2==0){
      if(s[i]=='R'||s[i]=='U'||s[i]=='D')cnt1++;
    }
    else{
      if(s[i]=='L'||s[i]=='U'||s[i]=='D')cnt2++;
    }
  }

  if(cnt1+cnt2==s.size())cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}