#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

int main(){
    int N;
    cin >> N;
    vector<string>S(N);
    vector<int>A(N);
    REP(i, N){
        cin >> S.at(i) >> A.at(i);
    }
    string X;
    cin >> X;
    bool flag = false;
    ll ans = 0;
    REP(i, N){
        if(flag) ans += A.at(i);
        if(S.at(i) == X) flag = true;
    }
    print(ans);
}

