#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k,c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  vector<int> fast(n,-1);
  vector<int> slow(n,-1);
  int day = 1;
  rep(i,n){
    if(s[i]=='o'){
      fast[i]=day;
      if(day==k)break;
      day++;
      i+=c;
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='o'){
      slow[i]=day;
      if(day==1)break;
      day--;
      i-=c;
    }
  }
  rep(i,n){
    if(fast[i]==-1)continue;
    if(fast[i]==slow[i])cout << i+1 << endl;
  }
}