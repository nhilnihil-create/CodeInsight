#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int a[N], b[N];
bool is[N];

int n;
priority_queue<pii> tf;

void check(int x){
  if(is[x]){
    return ;
  }
  if(b[x] > a[x] && b[x] > b[(x-1+n)%n] + b[(x+1)%n]){
    tf.push(mp(b[x], x));
    is[x] = true;
  }
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a[i];
  }
  for(int i = 0 ; i < n ; i ++ ){
    cin >> b[i];
  }
  for(int i = 0 ; i < n; i ++ ){
    check(i);
  }
  ll res = 0;
  int idx;
  ll dd;
  while(!tf.empty()){
    idx = tf.top().se;
    tf.pop();
    is[idx] = false;
    dd = b[idx] - a[idx];
    res += dd / (b[(idx+1)%n] + b[(idx-1+n)%n]);
    b[idx] = a[idx] + (dd % (b[(idx+1)%n] + b[(idx-1+n)%n]));
    check((idx-1+n)%n);
    check((idx+1)%n);
  }
  for(int i = 0 ; i < n ; i ++ ){
    if(a[i] != b[i]){
      cout << -1;
      return 0;
    }
  }
  cout << res << "\n";
  return 0;
}
