#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define INF 1000000000

int main(){
  set<string> keys;

  int n,m;
  cin >> n;

  rep(i,n){
    char s[12];
    scanf("%s", s);
    string key(s);
    keys.insert(key);
  }

  cin >> m;

  bool door=false;
  rep(i,m){
    char s[12];
    scanf("%s", s);
    string key(s);
    if( keys.find(key) != keys.end() ){ //find
      if(!door)
	cout << "Opened by " << key << endl;
      else
	cout << "Closed by " << key << endl;
      door = !door;

    }else {
      cout << "Unknown " << key << endl;

    }
  }

}