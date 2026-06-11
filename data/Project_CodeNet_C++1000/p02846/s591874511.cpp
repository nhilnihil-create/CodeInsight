//includes
#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
#include<queue>
#include<iomanip>
#include<numeric>
#include<assert.h>
#include<cstring>
#include<unordered_map>
#include<bitset>

//macros and consts
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORE(i,a) for(auto &i : a)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define accm accumulate
#define Fi first
#define Se second
#define INF 1e9
#define llINF (1LL<<60)
#define mINF -1e9
#define mllINF -(1LL<<60)
#define endl "\n"
#define CONT continue
#define BRK break
#define modulo(n, m) (((n)%(m)+(m))%m)

//shorter types
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vc = std::vector<char>;
using vll = std::vector<long long>;
using vs = std::vector<string>;
using Mi = map<int,int>;
using Mll = map<ll,ll>;
using UMi = unordered_map<int,int>;
using UMll = unordered_map<ll,ll>;
using Pi = pair<int,int>;
using Pll = pair<ll,ll>;
using vPi = vector<Pi>;
using vPll = vector<Pll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using pqgi = priority_queue<int,vector<int>,greater<int>>;
using pqsi = priority_queue<int,vector<int>,less<int>>;
using pqgll = priority_queue<int,vector<int>,greater<int>>;
using pssll = priority_queue<int,vector<int>,less<int>>;
template<class T>
using vec = vector<T>;

//here begins your code
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  unsigned long T1,T2;
  unsigned long A1,A2,B1,B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  if(A1 * T1 + A2 * T2 == B1 * T1 + B2 * T2){
  	cout << "infinity" << endl;
  	return 0;
  }


  if(B1 * T1 + B2 * T2 > A1 * T1 + A2 * T2){
  	swap(A1,B1);
  	swap(A2,B2);
  	//A goes further in the end;
  }

  if(A1 * T1 > B1 * T1){
  	cout << 0 << endl;
  	return 0;
  }

  long diff_total = (A1 * T1 + A2 * T2) - (B1 * T1 + B2 * T2);
  long diff_erst = B1 * T1 - A1 * T1;
  if(diff_erst % diff_total == 0){
  	cout << diff_erst / diff_total * 2L << endl;
  }
  else{
  	cout << diff_erst / diff_total * 2L + 1L << endl;
  }

  return 0;
} 