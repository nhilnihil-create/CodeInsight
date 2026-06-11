#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 200000;
int target[1 + nmax], v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> target[i];
  for(int i = 0;i < n; i++)
    cin >> v[i];
  queue<int> q;
  for(int i = 0;i < n; i++)
    q.push(i);
  ll result = 0;
  while(0 < q.size()){
    int pos = q.front();
    q.pop();
    if(v[pos] < v[(pos + n - 1) % n] || v[pos] < v[(pos + 1) % n])
      continue;
    if(v[pos] <= target[pos])
      continue;

    int stop = max(target[pos], max(v[(pos + 1) % n], v[(pos + (n - 1)) % n]));
    int jumps = (v[pos] - stop) / (v[(pos + 1) % n] + v[(pos + (n - 1)) % n]);
    jumps = max(jumps, 1);
    if(0 < jumps){
      v[pos] -= jumps * (v[(pos + 1) % n] + v[(pos + (n - 1)) % n]);
      q.push((pos + 1) % n);
      q.push((pos + n - 1) % n);
      q.push(pos);
      result += jumps;
    }
    if(v[pos] < target[pos])
      break;
  }
  for(int i = 0;i < n; i++)
    if(v[i] != target[i]) {
      cout << -1;
      return 0;
    }
  cout << result;
  return 0;
}
