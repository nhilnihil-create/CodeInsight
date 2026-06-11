#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

int main(){
  int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
  string s; cin >> s;

  int count = 0;
  bool ok = true;

  for(int i=a-1;i<max(c,d);i++){
    if(s.at(i)=='#') count++;
    else count = 0;

    if(count==2) ok = false;
  }

  if(c>d){
    bool space = false;
    for(int i=b-1;i<d;i++){
      string tmp = "";
      rep(j,3){
        tmp.push_back(s.at(i+j-1));
      }
      if(tmp=="...") space = true;
    }
    if(!space) ok = false;
  }

  if(ok) puts("Yes");
  else puts("No");

}
