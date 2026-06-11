#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N; cin >> N;
  string s;
  unordered_map<string, int> cnt;
  rep(i,N){
    cin >> s;
    sort(all(s));
    cnt[s]++;
  }

  ll retval = 0;
  for (auto p:cnt){
    ll n = p.second;
    retval += n*(n-1)/2;
  }

  cout << retval << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}

