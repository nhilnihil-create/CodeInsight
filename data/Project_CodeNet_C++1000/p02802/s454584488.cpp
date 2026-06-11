#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m; cin >> n >> m;
  vector<pair<int,string>> ps(m);
  rep(i,m){
    int p; cin >> p;
    string s; cin >> s;
    ps[i] = make_pair(p,s);
  }

  int ac=0,wa=0;
  vector<bool> acd(n+1,false);
  /*cout << "size: " << acd.size() << endl;
    cout << acd[3] << endl;*/
  vector<int> wan(n+1,0);
  rep(i,m){
    int p = ps[i].first;
    string s = ps[i].second;
    //cout << "p: " << p << " " << s << " acd: " << acd[p] << endl;
    if(!acd[p]){
      if(s=="AC"){
	ac++;
	acd[p]=true;
	wa += wan[p];
      }
      else wan[p]++;
    }
    //printf("ac: %d wa: %d\n",ac,wa);
  }

  printf("%d %d\n",ac,wa);
  
  return 0;
}
