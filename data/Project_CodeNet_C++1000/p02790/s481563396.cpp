#include <bits/stdc++.h>
//#include <atcoder/fenwicktree>
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
//#define _GLIBCXX_DEBUG

using ll = long long;
using ull = unsigned long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll mod = 1e9+7;
void chmod(ll &M){
  if(M >= mod) M %= mod;
  else if(M < 0){
     M += (abs(M)/mod + 1)*mod;
    M %= mod;
}
}
ll modpow(ll x, ll n){
   if(n==0) return 1;
  ll res=modpow(x, n/2);
 if(n%2==0) return res*res%mod;
else return res*res%mod*x%mod;
}
int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  else return GCD(b, a % b);
}

using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    cerr << a + a << endl;
    string a_f = a;
    string b_f = b;
    
    //stoiで文字列型を数値型に変換
    int a_l = stoi(a) - 1;
    int b_l = stoi(b) - 1;
    
    rep(i, b_l) {
        a += a_f;
    }
    rep(i, a_l) {
        b += b_f;
    }
   // デバッグ
    cerr << a << " " << b << "\n";
    if(a <= b) cout << a << "\n";
    else cout << b << "\n";
 }