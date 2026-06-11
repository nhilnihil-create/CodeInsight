#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[100];
long long int mem[100][21];
bool vis[100][21];

void rec(int p, int x) {
  int nx;
  if(x < 0 || x > 20) return;
  if(p >= N-1) return;
  if(vis[p][x]) return;

  mem[p][x] = 0;

  nx = x + num[p];
  if(nx >= 0 && nx <= 20) {
    rec(p+1, nx);
    mem[p][x] += mem[p+1][nx];
  }

  nx = x - num[p];
  if(nx >= 0 && nx <= 20) {
    rec(p+1, nx);
    mem[p][x] += mem[p+1][nx];
  }

  vis[p][x] = true;
}

main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> num[i];
  }
  fill(mem[0], mem[100], 0);
  fill(vis[0], vis[100], false);
  mem[N-1][num[N-1]] = 1;
  vis[N-1][num[N-1]] = true;
  rec(1, num[0]);
  cout << mem[1][num[0]] << endl;
}