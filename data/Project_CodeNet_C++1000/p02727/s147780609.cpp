#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

long long MOD = 10000000000 + 7;

template<class T>
using MaxHeap = std::priority_queue<T>;

int main(){
  cout << setprecision(10);
  int X,Y,a,b,c;
  cin >> X >> Y >> a >> b >> c;

  MaxHeap<pli> pq;

  for(int i = 0; i < a; i++){
    ll tmp; cin >> tmp;
    pq.push(make_pair(tmp, 0));
  }
  for(int i = 0; i < b; i++){
    ll tmp; cin >> tmp;
    pq.push(make_pair(tmp, 1));
  }
  for(int i = 0; i < c; i++){
    ll tmp; cin >> tmp;
    pq.push(make_pair(tmp, 2));
  }

  ll ans = 0;
  int x=0,y=0,z = 0;
  while(x + y + z < X+Y){
    auto now = pq.top();
    int col = now.second;
    ll val = now.first;
    // cerr << col << " " << val << endl;
    pq.pop();

    if(col==0 && x < X){
      ans += val;
      x++;
    }
    if(col==1 && y < Y){
      ans += val;
      y++;
    }

    if(col==2){
      ans += val;
      z++;
    }
  }
  cout << ans << endl;
}
