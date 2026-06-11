#include<iostream>
#include<algorithm>
#include<set>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;

int main(){
  ll tmp;
  set<ll> cnt;
  rep(i, 3){
    cin >> tmp;

    cnt.insert(tmp);
  }

  if(cnt.size() == 2)
    cout << "Yes\n";
  else
    cout << "No\n";
  
  return 0;
}
