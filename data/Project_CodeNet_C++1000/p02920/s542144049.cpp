#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

multiset<ll> num;
priority_queue<pair<ll, ll>> task, waiting;

int main(int argc, char const *argv[]) {
  ll N, a;
  std::cin >> N;
  for(int i=0;i<(1<<N);i++) {
    std::cin >> a;
    num.insert(a);
  }
  auto itr = num.end();
  itr--;
  task.push(make_pair(*itr, N));
  //std::cout << *itr << " " << N<< '\n';
  num.erase(itr);
  while(!num.empty()){
    while(!task.empty()){
      ll now = task.top().first, c=task.top().second;
      task.pop();
      itr = num.lower_bound(now);
      if(itr==num.begin()){
        std::cout << "No" << '\n';
        return 0;
      }
      itr--;
      //std::cout << *itr << " " << c - 1 << '\n';
      if(c!=1) waiting.push(make_pair(*itr, c-1)),waiting.push(make_pair(now, c-1));
      num.erase(itr);
    }
    while(!waiting.empty()){
      task.push(make_pair(waiting.top().first, waiting.top().second));
      waiting.pop();
    }
  }
  std::cout << "Yes" << '\n';
  return 0;
}
