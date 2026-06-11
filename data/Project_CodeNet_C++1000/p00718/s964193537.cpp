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

int n;
string s, t;
char ex[] = {'m', 'c', 'x', 'i'};
int _int[] = {1000, 100, 10, 1};

int dec(string s)
{
  int res = 0;
  rep(i, s.size()){
    int tmp = 0;
    if(s[i] >= '2' && s[i] <= '9'){
      tmp += s[i] - '0';
      rep(k, 4) if(ex[k] == s[i+1]) tmp *= _int[k];
      res += tmp;
      i += 1;
    }
    else{
      rep(k, 4) if(ex[k] == s[i]) res += _int[k];
    }
  }
  return res;
}

string enc(int n)
{
  string s = "";
  rev(k, 4){
    int tmp = n % 10;
    if(tmp) s += ex[k];
    if(tmp > 1) s += tmp + '0';
    n /= 10;
  }
  reverse(ALL(s));
  return s;
}

int main()
{
  cin >> n;

  while(n--){
    cin >> s >> t;
    cout << enc(dec(s) + dec(t)) << endl;
  }

  return 0;
}