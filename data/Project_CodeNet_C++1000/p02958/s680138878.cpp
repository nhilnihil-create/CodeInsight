#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const int INF=1e9+5;
typedef long long ll;

int main() {
  ll N;
  cin>>N;
  ll a[N];
  rep(i,N){
    cin>>a[i];
  }
  ll k=0;
  rep(i,N-1){
    if(a[i]!=i+1){
      k++;
    }
  }
  if(k<=2){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}