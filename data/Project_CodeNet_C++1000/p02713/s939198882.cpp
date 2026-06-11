#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int gcd(int a, int b){
  if (b ==  0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    REP(i,1,n+1)REP(j,1,n+1)REP(k,1,n+1){
        int index = gcd(i, j);
        ans += gcd(index, k);
    }
    cout << ans << endl;
    return 0;
}
