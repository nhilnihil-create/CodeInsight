#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll INF = pow(10,9)+7;

int main(){
  int n,ans,end;
  ans = 1;
  cin >> n;
  vector<P> v;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    v.push_back(make_pair(a+b,a-b));
  }
  sort(v.begin(),v.end());
  end=v[0].first;
  rep(i,n){
    if(v[i].second>=end){
      end = v[i].first;
      ans++;
    }
  }
  cout << ans << endl;
}