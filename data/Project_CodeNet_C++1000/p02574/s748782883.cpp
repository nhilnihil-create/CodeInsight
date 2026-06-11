// In god we trust
 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <signal.h>
#include <thread>
#include <pthread.h>
#include <omp.h>
 
#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define Q queue
#define Qi Q<int>
#define INF 1000000000 
#define LINF 1000000000000000000
#define int long long
#define _USE_MATH_DEFINES
using namespace std;
using namespace std::chrono;

unordered_map<int, int> factor(int n){
  int cnt = 0;
  unordered_map<int, int> m;
  int nn = n;
  while (!(nn & 1))
    cnt++, nn /= 2;
  if(cnt)
    m[2] = cnt;
  for (int i = 3; i <= sqrt(n); i++){
    cnt = 0;
    while(nn % i == 0)
      nn /= i, cnt++;
    if (cnt)
      m[i] = cnt;
  }
  if (nn > 2)
    m[nn] = 1;
  
  return m;
}
const int MAXN = 1000100;
int spf[MAXN];

set<int> sieve_factor(int n){
  set<int> s;
  while(n != 1)
    s.insert(spf[n]), n /= spf[n];
  return s;
}

signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 2; i < MAXN; i++)
    spf[i] = i;

  for (int i = 2; i < MAXN; i++)
    if (spf[i] == i)
      for (int j = i * i; j < MAXN; j += i)
	if (spf[j] == j)
	  spf[j] = i;
  
  int gcd = __gcd(a[0], a[1]);

  for (int i = 2; i < n; i++)
    gcd = __gcd(gcd, a[i]);

  if (gcd == 1){
    set<int> factors;
    bool could = true;
    for (int i = 0; i < n; i++)
      for (auto item: sieve_factor(a[i]))
	if (factors.find(item) != factors.end()){
	  could = false;
	  break;
	}else
	  factors.insert(item);
    if (could)
      cout << "pairwise coprime" << endl;
    else
      cout << "setwise coprime" << endl;
  }else{
    cout << "not coprime" << endl;
  }
  
}
