#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  int N; cin >> N;
  map<ll,ll> mp;
  ll ans = 0;
  ll A[N];
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    A[i] = a;
    ans += mp[a];
    mp[a]++;
   
  }
  for(int i=0;i<N;i++){
    cout << ans-mp[A[i]]+1<< endl;
  }
}