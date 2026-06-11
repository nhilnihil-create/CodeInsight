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
     ll A,B;
     cin >> A>>B;
     ll d = gcd(A,B);
     vector<ll> a;
     ll dd = d;
     for(ll i = 2;i*i<=d;++i){
          if(dd%i==0){
               a.push_back(i);
               dd/=i;
               while(dd%i==0&&dd>1){
                    dd/=i;
               }
          }
     }
     if(dd!=1) a.push_back(dd);
     cout << 1+a.size() <<endl;
}