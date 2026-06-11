#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  while(k>0){
    vector<int> imos(n+1);
    vector<pair<int,int>> qu;
    rep(i,n){
      qu.push_back({max(0,i-a[i]),min(n-1,i+a[i])});
    }
    rep(i,n){
      imos[qu[i].first]++;
      imos[qu[i].second+1]--;
    }
    vector<int> na(n);
    na[0] = imos[0];
    rep1(i,n-1){
      na[i] = imos[i] + na[i-1];
    }
    swap(a,na);
    k--;
    rep(i,n) {
      if(a[i]!=n) break;
      else if(i==n-1) k=0;
    }
  }
  rep(i,n) cout << a[i] <<" ";
  cout << endl;

  return 0;
    

}
