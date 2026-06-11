#include <iostream>
#include <string>
#define REP(i,n) for(int i=0;i<(n);++i)
#define MOD 1000000007
using namespace std;

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  if(H > W) swap(H, W);
  int ret = (N + W - 1) / W;
  cout << ret << endl;
}