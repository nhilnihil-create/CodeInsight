#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  int N; cin >> N;
  string s; cin >> s;
  int cnt = 0;
  for(int i=0;i<N;i++){
    if(s[i]=='R') cnt++;
  }
  int ans = 0;
  for(int i=0;i<cnt;i++){
    if(s[i]=='W') ans++;
  }
  cout << ans << endl;
 
}
