#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N,K;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>N>>K;

  if (K > (N-1)*(N-2)/2) {
    cout<<"-1\n";
    return 0;
  }

  vector<pii> res;
  for(int i=2;i<=N;i++) res.pb({1,i});
  queue<pii> q;
  for(int i=2;i<=N;i++) for(int j=i+1;j<=N;j++) q.push({i,j});

  while (K++ < (N-1) * (N-2)/2) res.pb(q.front()), q.pop();

  cout<<res.size()<<endl;
  for(auto pr:res) cout<<pr.fst<<' '<<pr.snd<<endl;

  return 0;
}
