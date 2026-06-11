#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <ios>
#include <ctype.h>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <list>
#include <deque>
#include <time.h>
#include <random>
#include <iomanip>
#include <fstream>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define pint pair<int,int>
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
using Graph_weighted = vector<vector<pair<int,int>>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
vector<string>ans;
vector<char>abc;
void dfs(string s,int n){
  if(n == s.size()){
    ans.push_back(s);
    return;
  }
  set<char>cnt;
  rep(i,s.size())cnt.insert(s[i]);
  rep(i,cnt.size() + 1){
    dfs(s + abc[i],n);
  }
}
int main(){
  int n;
  cin >> n;
  rep(i,26)abc.push_back('a' + i);
  dfs("a",n);
  sort(all(ans));
  rep(i,ans.size())cout << ans[i] << endl;
  return 0;
}
