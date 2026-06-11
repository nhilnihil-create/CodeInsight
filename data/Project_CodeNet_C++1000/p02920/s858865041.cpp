//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;

const long long INF = 1LL << 55;

#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(void){
   int n;cin >> n;
   map<int,int> m;
   rep(i,(1<<n)){
      int a;cin >> a;
      m[-a]++;
   }
   priority_queue<int> q;
   q.push(n);
   for(auto i : m){
      int k = i.second;
      if(k > q.size()){
         cout << "No" << endl;
         return 0;
      }else{
          queue<int> p;
         for(int j = 0;j < k;j++){
            int x = q.top();q.pop();
            p.push(x);
         }
         for(int j = 0;j < k;j++){
            int y = p.front();p.pop();
            for(int l = 0;l < y;l++) q.push(l);
         }
      }
   }
   cout << "Yes" << endl;
   return 0;
   
}
