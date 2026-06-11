#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  set<ll> num;
  for(int i=4;i<=1000000;i*=2) num.insert(i);
  bool flag = true;
  if(n==1||n==2) flag = false;
  if((n%2==0&&(num.upper_bound(n)!=num.upper_bound(n-2)))) flag = false;
  if(!flag){
    std::cout << "No" << '\n';
    return 0;
  }
  std::cout << "Yes" << '\n';
  std::cout << "1 2" << '\n';
  std::cout << "2 3" << '\n';
  std::cout << "3 " << 1+n << '\n';
  std::cout << 1+n << " " << 2+n << '\n';
  std::cout << 2+n << " " << 3+n << '\n';
  if(n==6){
    std::cout << 5 << " " << 6 << '\n';
    std::cout << 6 << " " << 3 << '\n';
    std::cout << 3 << " " << 11 << '\n';
    std::cout << 11 << " " << 12 << '\n';
    std::cout << 4 << " " << 11 << '\n';
    std::cout << 2 << " " << 10 << '\n';
    return 0;
  }
  if(n%2==1){
    for(int i=4;i<=n;i+=2){
      std::cout << i << " " << i+1  << '\n';
      std::cout << i+1 << " " << 2 << '\n';
      std::cout << 3 << " " << i+n << '\n';
      std::cout << i+n << " " << i+n+1 << '\n';
    }
  }else{
    for(int i=4;i<=n-5;i+=2){
      std::cout << i << " " << i+1  << '\n';
      std::cout << i+1 << " " << 2 << '\n';
      std::cout << 3 << " " << i+n << '\n';
      std::cout << i+n << " " << i+n+1 << '\n';
    }
    std::cout << n-1 << " " << n << '\n';
    std::cout << n << " " << (n^(n-1)) << '\n';
    std::cout << (n^(n-1)) << " " << 2*n-1 << '\n';
    std::cout << 2*n-1 << " " << 2*n << '\n';
    std::cout << n-4 << " " << n-3  << '\n';
    std::cout << n-3 << " " << n-2  << '\n';
    std::cout << n-2 << " " << n-1  << '\n';
    std::cout << n-1 << " " << 2*n-4  << '\n';
    std::cout << 2*n-4 << " " << 2*n-3  << '\n';
    std::cout << 2*n-3 << " " << 2*n-2  << '\n';
  }
  return 0;
}
