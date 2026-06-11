#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define rrev(i, m, n) for(int (i)=(n)-1; (i)>=(m); (i)--)
#define erev(i, m, n) for(int (i)=(n); (i)>=(m); (i)--)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define pb            push_back
template<class T, class S> inline pair<T, S> mp(T x, S y){ return make_pair(x, y); }
template<class T, class S> inline bool minup(T& m, S x){ return m>(T)x ? (m=(T)x, true) : false; }
template<class T, class S> inline bool maxup(T& m, S x){ return m<(T)x ? (m=(T)x, true) : false; }

static const int    INF = 1000000000;
static const ll     MOD = 1000000007LL;
static const double EPS = 1E-12;

const int MAX_N = 123456;
bool flag[2*MAX_N+1];
int prime[2*MAX_N+1];
int n;

int getPrime(int MAX_N = MAX_N, bool flag[] = flag, int prime[] = prime)
{
  int ptr = 0;
  prime[ptr++] = 2;
  for(int i=4; i<=MAX_N; i+=2) flag[i] = true;
  for(int i=3; i<=MAX_N; i+=2){
    if(!flag[i]){
      prime[ptr++] = i;
      for(int j=2*i; j<=MAX_N; j+=i) flag[j] = true;
    }
  }
  return ptr;
}


int main()
{
  int ptr = getPrime(2 * MAX_N);

  while(cin >> n, n){
    cout << upper_bound(prime, prime + ptr, 2 * n) - upper_bound(prime, prime + ptr, n) << endl;

  }
  return 0;
}