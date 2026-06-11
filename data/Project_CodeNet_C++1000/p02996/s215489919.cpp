#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll n;
  cin >> n;

  ll a,b,sum=0;
  std::vector<pair<ll,ll>> task(n);
  rep(i,n){
    cin >> a;
    cin >> b;
    task.at(i)=make_pair(b,a);
  }

  sort(all(task));

  for(auto i:task){
    sum+=i.second;
    if(i.first<sum){
      cout << "No" << endl;
      return 0;
    }


  }

  cout << "Yes" << endl ;


  }
