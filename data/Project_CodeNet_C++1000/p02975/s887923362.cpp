#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
/*
v[1] ^ v[2] ^ v[3] = 0
v[2] ^ v[3] ^ v[4] = 0
=> v[1] ^ v[4] = 0
=> if n is not divisible by 3 all elements should be equal
*/
int const nmax = 100000;
std::map<int,int> frec;
int v[5 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) 
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    frec[v[i]]++;
  int verdict = 1;
  if(0 < (n % 3)) {
    verdict = (frec[v[1]] == n);
    if(0 < v[1])
      verdict = 0;
  } else {
    int total = 0;
    for(int i = 1;i <= n; i++) { 
      if(0 < (frec[v[i]] % (n / 3))) 
        verdict = 0;
      else if(0 < frec[v[i]]) {
        total ^= v[i];
        frec[v[i]] -= n / 3;
      }
    }
    if(0 < total)
      verdict = 0;
  }
  if(verdict == 1)
    std::cout << "Yes";
  else
    std::cout << "No";

  return 0;
}
