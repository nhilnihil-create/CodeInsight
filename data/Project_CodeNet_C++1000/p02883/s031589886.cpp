#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n;cin>>n;
  ll k;cin>>k;
  vector<int> a(n), f(n);
  rep(i, n)cin>>a[i];
  rep(i, n)cin>>f[i];

  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());

  vector<pi> ts;
  rep(i, n) ts.push_back( {a[i], f[i]} );

  ll min=-1,max=pow(10LL, 18)+1, mid;
  while(max-min>1){
    mid = (max+min)/2;
//cout<<"-------------"<<endl<<min<<' '<<max<<endl;

    ll ck=k;
    // tsの中に入っているスコアがすべてmid以下にできるか検証
    for(auto p: ts){
      ll score = (ll)p.first*(ll)p.second;
      if(score<=mid)continue;

      ll new_a = mid/p.second;
      ck -= (p.first-new_a);
    }

//cout<<ck<<endl;
    // 実現可能なら減らす
    if(ck>=0)max=mid;
    else min=mid;
  }

//cout<<min<<' '<<max<<endl;

  cout<<max<<endl;

  return 0;
}