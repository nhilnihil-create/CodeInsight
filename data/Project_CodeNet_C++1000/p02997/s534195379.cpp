#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<int,int>;
const int INF=1001001001;
const int NMAX=8;
const int mod = 1000000007;

int main()
{
  int n,k;
  cin>>n>>k;
  //cout<<n;

  if ((n-1)*(n-2)<k*2){
    cout<<-1;
    return 0;
  }

  vector<P> v;
  //cout<<'k';
  for(int i=1;i<n;i++)v.push_back(make_pair(0,i));
  int now=(n-1)*(n-2)/2;
//  cout<<now;

  for (int i=1;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(now>k){
        v.push_back(make_pair(i,j));
        now--;
      }
    }
  }
  int temp=v.size();
cout<<temp<<endl;
  rep(i,temp){

    cout<<v[i].first+1<<' '<<v[i].second+1<<endl;
  }





}
