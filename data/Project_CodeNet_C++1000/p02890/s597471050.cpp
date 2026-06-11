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


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

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
#define int long long
int N;
vector<int> C,D;
//here begins your code
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  C.resize(N);
  D.resize(N + 1);
  REP(i,N){
  	int a;
  	cin >> a;
  	a--;
  	C[a]++;
  	D[C[a]]++;
  }
  vector<int> S;
  S.resize(N+1);

  for(int i = 1; i < N+1; i++){
  	S[i] = S[i-1] + D[i];
  }

  for(int K = 1; K <= N; K++){
  	int ok = 0; int ng = N+1;
  	while(ng - ok > 1){
  		int mid = (ng + ok)/2;
  		if(S[mid] >= K * mid){
  			ok = mid;
  		}
  		else{
  			ng = mid;
  		}
  	}

  	cout << ok << endl;
  }
  //check types
  //do not eb if you resize
  //resize before you access by idx
  return 0;
} 