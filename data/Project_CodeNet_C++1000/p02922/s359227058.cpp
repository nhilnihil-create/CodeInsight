#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const ll INF = 1001001001;

int main(){
  int a ,b;
  cin >> a >> b;
  int cnt = 0;
  int plug = 1;
  while(true){
    if (plug >= b) break;
    plug += a-1;
    cnt++;
  }
  cout << cnt << endl;
}
