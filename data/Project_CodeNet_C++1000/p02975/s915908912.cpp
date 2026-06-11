#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Reve(a) reverse(a.begin(), a.end())
typedef long long ll;
const ll MOD = 1e9+7;

/*ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}*/
/*ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}*/

/*ll lcm(ll a, ll b){
  ll g = gcd(a, b);
  b /= g;
  a *= b;
  return a;
}*/

/*int dfs(vector<int> &T, vector<int> &C, int i, int sum, int g, int count){
   
}*/

int main(){
  int n, a; cin >> n;
  vector<int> A(n);
  set<int> B; int ch = 0;
  if(n%3!=0){
    rep(i, n){
      cin >> A[i];
      if(A[i]!=0){
        cout << "No" << endl;
        ch = 1;
        break;
      }
    }
    if(ch==0) cout << "Yes" << endl;
  }
  else{
  rep(i,n) {cin >> A[i]; B.insert(A[i]);}
  Sort(A);
  if(B.size()>3) cout << "No" << endl;
  else if(B.size()==1){
    bitset<32> d(A[0]);
    if((d^d^d)==0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else if(B.size()==3){
    int m1=A[n/3-1], m2=A[n/3], m3=A[n*2/3-1], m4=A[n*2/3];
    if(m1!=m2&&m3!=m4){
      bitset<32> d(m1);
      bitset<32> e(m2);
      bitset<32> f(m4);
      bitset<32> g(0);
      //bitset<32> h = d^e;
      if((d^e^f)==g) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }
  else {
    int m1=A[n/3-1], m2=A[n/3], m3=A[n*2/3-1], m4=A[n*2/3];
    if(m3!=m4){
      bitset<32> d(m3);
      bitset<32> e(m4);
      //bitset<32> f(m3);
      bitset<32> g(0);
      //bitset<32> h = d^e;
      if((d^e^d)==g) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else if(m1!=m2){
      bitset<32> d(m1);
      bitset<32> e(m2);
      //bitset<32> f(m3);
      bitset<32> g(0);
      //bitset<32> h = d^e;
      if((d^e^e)==g) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }  
  }
}