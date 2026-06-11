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

int main(int argc, char const *argv[]) {
  ll N, P=1000000007;
  string S, T="";
  std::cin >> N;
  std::cin >> S;
  string s = S;
  for(int i=0;i<2*N;i++){
    if(i==0) T +='L';
    else if(S[i]!=S[i-1]) T+='L';
    else T+='R', S[i]=(S[i]=='W'?'B':'W');
  }
  bool flag = true;
  std::vector<ll> L(2*N, 0), R(2*N, 0);
  for(int i=0;i<2*N;i++) {
    L[i] = (i==0?0:L[i-1]) + (T[i]=='L'?1:0);
    R[i] = (i==0?0:R[i-1]) + (T[i]=='R'?1:0);
  }
  if(L[2*N-1]!=R[2*N-1]) flag = false;
  if(T[2*N-1]!='R') flag = false;
  if(s[0]=='W' || s[2*N-1]=='W') flag = false;
  ll ans = 1;

  for(int i=0;i<2*N;i++){
    if(T[i]=='R') ans = (ans * (L[i] - R[i] + 1))%P;
    if(ans <0) flag = false;
  }
  //std::cout << T << '\n';
  for(int i=1;i<=N;i++) ans = (ans*i)%P;
  std::cout << (flag?ans:0) << '\n';
  return 0;
}
