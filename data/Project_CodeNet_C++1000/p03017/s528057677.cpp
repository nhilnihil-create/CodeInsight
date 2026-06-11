#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  a--;b--;c--;d--;
  string s;
  cin >> s;
  int type=-1;
  if(a<b&&c<d) type=1;
  else if(a<b&&d<c) type=2;
  else type =3;
  bool can = true;
  if(type==1){
    for(int i=a+1;i<d-1;i++){
        if(s[i]=='#'&&s[i+1]=='#')
          can = false;
    }
  }
  else if(type==2){
    for(int i=a+1;i<c-1;i++){
        if(s[i]=='#'&&s[i+1]=='#')
          can = false;
    }
    bool can2=false;
    for(int i=b-1;i<=d-1;i++){
      if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.')
          can2 = true;
    }
    if(can2==false) can = false; 
  }
  else if(type==3){
    for(int i=a+1;i<c-1;i++){
        if(s[i]=='#'&&s[i+1]=='#')
          can = false;
    }
    for(int i=b+1;i<d-1;i++){
        if(s[i]=='#'&&s[i+1]=='#')
          can = false;
    }
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
