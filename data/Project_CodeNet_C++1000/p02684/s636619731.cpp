#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,k,now=0,w;
  cin >> n>>k;
  vector<ll> a(n),memo(n,0),jun;
  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  rep(i,k){
    if(memo[now]==1){
      break;
    }
    jun.push_back(now);
    memo[now]=1;
    now=a[now];
    if (i + 1 == k){
      cout << now + 1 <<endl;
      return 0;
    }
  }
  if(now!=0){
    rep(i,jun.size()){
      if(jun[i]==now){
        w=i;
        k-=i;
        k%=(jun.size()-i);
        break;
      }
    }
    cout << jun[k+w]+1<<endl;
  }else{
    k%=jun.size();
    cout << jun[k]+1<<endl;
  }
}
