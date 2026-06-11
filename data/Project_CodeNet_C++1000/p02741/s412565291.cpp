#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef pair<ll,ll> pl;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()
//#define max(a,b) (a>b ? a : b)
//#define min(a,b) (a<b ? a : b)
 
const int MOD = 998244353;
const int INF = 100000002;
const double PI =4*atan(1);
const double eps = 1e-7;
const long long oo = 1e18;

int main(){
  vector<int> data = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int K;
  cin >> K;
  cout << data[K-1] << endl;
}