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
#define SEG_LEN (1 << 18)
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
int main(){
  string s;
  cin >> s;
  string back = "XXOXOXOOOXOXOXOXXOXXOXOO";
  int n = s.size();
  int ans = 0;
  rep(i,n){
    if(i == n - 1){
      if(back != s.substr(i,1))ans++;
    }
    else{
      if(back != s.substr(i,1)){
        ans++;
        back = s.substr(i,1);
      }
      else{
        ans++;
        back = s.substr(i,2);
        i++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
 