#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
//ranker
using namespace std;

#define REPS(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) REPS(i, 0, n)
#define RREP(i, n) REPS(i, 1, n + 1)
#define DEPS(i, a, n) for (int i = (a); i >= n; --i)
#define DEP(i, n) DEPS(i, n, 0)

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using D = double;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(1){
  int n, m;
  cin >> n >> m;
  if(n==0 && m==0) break;

  int Taro[n], Hanako[m];

  REP(i, n) cin >> Taro[i];
  REP(i, m) cin >> Hanako[i];

  int tot_Taro=0, tot_Hanako=0;

  REP(i, n) tot_Taro += Taro[i];
  REP(i, m) tot_Hanako += Hanako[i];

  stable_sort(Taro, Taro+n);
  stable_sort(Hanako, Hanako+m);

  int num=-1;
  int dif;
  dif = tot_Hanako-tot_Taro;
  if(dif%2 != 0){
    cout << -1 << endl;
  }else{
    dif=dif/2;
  REP(i, m){
  if(binary_search(Taro, Taro+n, Hanako[i]-dif)){
      num = Hanako[i]-dif;
      cout << num << " "<< num+dif << endl;
      break;
  }
}if(num==-1) cout << -1 << endl;
}

}
  return 0;
}