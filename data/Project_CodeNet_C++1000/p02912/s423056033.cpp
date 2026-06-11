#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll gcd(ll a,ll b) {return  b ? gcd(b,a%b) : a;}
const long long INF = 1LL << 60;
const int mod = 1000000007;
const double PI = acos(-1.0);
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


int main () {
     int n,m;
     cin >> n >> m;
     vector<int>a(n);
     rep(i,n)cin >> a[i];
     priority_queue<int> que;
     rep(i,n) que.push(a[i]);
     rep(i,m){
          int x = que.top(); 
          que.pop();
          que.push(x/2);
     }
     ll ans =0;
     while(!que.empty()){
          ans+=que.top();
          que.pop();
     }
     cout << ans << endl;
}