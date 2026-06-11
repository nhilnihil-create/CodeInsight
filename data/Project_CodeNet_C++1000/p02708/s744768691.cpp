#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
typedef long long ll;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll N,K;
  cin >> N >> K;
  ll res = 0;
  for(ll i=K;i<=N+1;i++){
    res += i*N - i*(i-1) + 1;
  }
  cout << res%1000000007 << endl;
  
}